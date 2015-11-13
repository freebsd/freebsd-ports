# Created by: pdseniura@techie.com
# $FreeBSD$

PORTNAME=	c3270
PORTVERSION=	3.3.14ga11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://x3270.bgp.nu/download/03.03.14/
MASTER_SITES_VER_PATH=	${PORTVERSION:C/(0[0-9]\.0[0-9])/}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Full-screen curses-based remote login to IBM mainframes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/([0-9]\.[0-9])(\..*)/\1/}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_search_libiconv=${ICONV_LIB}

USES=		iconv readline gmake
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

# c3270's ./configure script supports these.
# Within it all options except DBCS are enabled by default.

OPTIONS_DEFINE=	OPENSSL READLINE PR3287 ANSI APL DBCS FT LOCAL_PROCESS \
		PRINTER SCRIPT TN3270E TRACE DOCS
OPTIONS_DEFAULT=	OPENSSL READLINE PR3287 ANSI APL FT LOCAL_PROCESS \
			PRINTER SCRIPT TN3270E TRACE
PR3287_DESC=		Build pr3287 component
ANSI_DESC=		Include NVT (ANSI) support
APL_DESC=		Include APL support
DBCS_DESC=		Include EBCDIC DBCS support
FT_DESC=		Include IND\$$FILE support
LOCAL_PROCESS_DESC=	Include Local Process support
PRINTER_DESC=		Include printer session support
SCRIPT_DESC=		Include scripting support
TN3270E_DESC=		Include TN3270-Extended support
TRACE_DESC=		Include trace support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ! ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--disable-ssl
.undef USE_OPENSSL
.endif

.if ! ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ARGS+=	--without-readline
.undef USE_READLINE
.endif

.if ! ${PORT_OPTIONS:MANSI}
CONFIGURE_ARGS+=	--disable-ansi
.endif

.if ! ${PORT_OPTIONS:MAPL}
CONFIGURE_ARGS+=	--disable-apl
.endif

# EBCDIC double-byte character set support is disabled by default
.if ${PORT_OPTIONS:MDBCS}
CONFIGURE_ARGS+=	--enable-dbcs
PLIST_SUB+=	DBCS=""
.else
PLIST_SUB+=	DBCS="@comment "
.endif

.if ! ${PORT_OPTIONS:MFT}
CONFIGURE_ARGS+=	--disable-ft
.endif

.if ! ${PORT_OPTIONS:MLOCAL_PROCESS}
CONFIGURE_ARGS+=	--disable-local-process
.endif

.if ! ${PORT_OPTIONS:MPRINTER}
CONFIGURE_ARGS+=	--disable-printer
.endif

.if ! ${PORT_OPTIONS:MSCRIPT}
CONFIGURE_ARGS+=	--disable-script
.endif

.if ! ${PORT_OPTIONS:MTN3270E}
CONFIGURE_ARGS+=	--disable-tn3270e
.endif

.if ! ${PORT_OPTIONS:MTRACE}
CONFIGURE_ARGS+=	--disable-trace
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/c3270.man \
		${STAGEDIR}${MANPREFIX}/man/man1/c3270.1
	@${INSTALL_MAN} ${WRKSRC}/x3270-script.man \
		${STAGEDIR}${MANPREFIX}/man/man1/x3270-script.1
	@${INSTALL_MAN} ${WRKSRC}/x3270if.man \
		${STAGEDIR}${MANPREFIX}/man/man1/x3270if.1
	@${INSTALL_MAN} ${WRKSRC}/ibm_hosts.man \
		${STAGEDIR}${MANPREFIX}/man/man5/ibm_hosts.5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for i in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/html/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor
	@${ECHO_MSG} "===> Extra Documentation installed in ${DOCSDIR}/html ."
.endif

.include <bsd.port.mk>
