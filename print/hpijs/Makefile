# $FreeBSD$

PORTNAME=	hpijs
PORTVERSION=	2.1.4
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	SF/hpinkjet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

CONFLICTS=	hplip-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking
USES=		ghostscript:run jpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS DOCS FOOMATIC
OPTIONS_DEFAULT=CUPS FOOMATIC
OPTIONS_SUB=	yes

FOOMATIC_DESC=	Install foomatic-rip and PPD files
INSTALL_TARGET=	install-exec install-foomatic

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS} || ${PORT_OPTIONS:MFOOMATIC}
CONFLICTS+=		foomatic-filters-*
USES+=			perl5 shebangfix
CONFIGURE_ARGS+=	--enable-foomatic-install
SHEBANG_FILES=		foomatic-rip
.else
CONFIGURE_ARGS+=	--disable-foomatic-install
.endif

.if ${PORT_OPTIONS:MCUPS}
BUILD_DEPENDS+=		cups>0:${PORTSDIR}/print/cups
RUN_DEPENDS+=		cups>0:${PORTSDIR}/print/cups
CONFIGURE_ARGS+=	--enable-cups-install
.else
CONFIGURE_ARGS+=	--disable-cups-install
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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gs_hpijs.png ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/hpijs_readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
