# $FreeBSD$

PORTNAME=	hpijs
PORTVERSION=	2.1.4
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF/hpinkjet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

CONFLICTS=	hplip-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-dependency-tracking
USES=		jpeg
USE_GHOSTSCRIPT_RUN=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS DOCS FOOMATIC
OPTIONS_DEFAULT=	CUPS FOOMATIC
FOOMATIC_DESC=	Install foomatic-rip and PPD files
INSTALL_TARGET=	install-exec install-foomatic

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS} || ${PORT_OPTIONS:MFOOMATIC}
CONFLICTS+=		foomatic-filters-*
USES+=			perl5 shebangfix
CONFIGURE_ARGS+=	--enable-foomatic-install
PLIST_SUB+=		FOOMATIC=""
SHEBANG_FILES=		foomatic-rip
.else
CONFIGURE_ARGS+=	--disable-foomatic-install
PLIST_SUB+=		FOOMATIC="@comment "
.endif

.if ${PORT_OPTIONS:MCUPS}
BUILD_DEPENDS+=		cups-base>0:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=		cups-base>0:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=	--enable-cups-install
PLIST_SUB+=		CUPS=""
.else
CONFIGURE_ARGS+=	--disable-cups-install
PLIST_SUB+=		CUPS="@comment "
.endif

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/cups|${LOCALBASE}/share/cups|g ; \
		s|/usr/lib/cups/filter|${LOCALBASE}/libexec/cups/filter|g' \
			${WRKSRC}/configure

.if empty(PORT_OPTIONS:MCUPS) && empty(PORT_OPTIONS:MFOOMATIC)
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${STAGEDIR}${PREFIX}/bin
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
