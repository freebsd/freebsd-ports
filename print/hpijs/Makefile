# $FreeBSD$

PORTNAME=	hpijs
PORTVERSION=	2.1.4
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF/hpinkjet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

CONFLICTS=	hplip-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-dependency-tracking
USE_GHOSTSCRIPT_RUN=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS DOCS FOOMATIC
OPTIONS_DEFAULT=	CUPS FOOMATIC
FOOMATIC_DESC=	Install foomatic-rip and PPD files

.include <bsd.port.pre.mk>

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS} || ${PORT_OPTIONS:MFOOMATIC}
CONFLICTS+=		foomatic-filters-*
USES=			perl5
CONFIGURE_ARGS+=	--enable-foomatic-install
PLIST_SUB+=		FOOMATIC=""
.else
CONFIGURE_ARGS+=	--disable-foomatic-install
PLIST_SUB+=		FOOMATIC="@comment "
.endif

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=		cups:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=	--enable-cups-install
PLIST_SUB+=		CUPS=""
.else
CONFIGURE_ARGS+=	--disable-cups-install
PLIST_SUB+=		CUPS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/cups|${LOCALBASE}/share/cups|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/configure

.if empty(PORT_OPTIONS:MCUPS) && empty(PORT_OPTIONS:MFOOMATIC)
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${PREFIX}/bin
.else
INSTALL_TARGET=	install-exec install-foomatic
.endif

post-install:
.if ${PORT_OPTIONS:MCUPS}
	@${LN} -s ${PREFIX}/bin/foomatic-rip ${LOCALBASE}/libexec/cups/filter/foomatic-rip
	@${LN} -s ${PREFIX}/share/ppd ${LOCALBASE}/share/cups/model/foomatic-ppds
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
