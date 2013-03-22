# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	dillo
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A fast, small graphical Web browser built upon fltk

LICENSE=	GPLv3

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		dillo.1
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec
CONFLICTS=	dillo-i18n-[0-9]* \
		dillo-0*
LATEST_LINK=	dillo2

OPTIONS_DEFINE=	COOKIES DEBUG IPV6 SSL THREADED_DNS
OPTIONS_DEFAULT=	COOKIES SSL THREADED_DNS
COOKIES_DESC=		Enable cookies
DEBUG_DESC=		Enable profiling and extra logging
SSL_DESC=		Enable (experimental) https support
THREADED_DNS_DESC=	Enable re-entrant resolver library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MCOOKIES}
CONFIGURE_ARGS+=	--enable-cookies
.else
CONFIGURE_ARGS+=	--disable-cookies
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-gprof --enable-rtfl
.else
CONFIGURE_ARGS+=	--disable-gprof --disable-rtfl
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MTHREADED_DNS}
CONFIGURE_ARGS+=	--enable-threaded-dns
.else
CONFIGURE_ARGS+=	--disable-threaded-dns
.endif

post-patch:
	@${MV} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.dist
	@${MV} ${WRKSRC}/dpid/dpidrc.in ${WRKSRC}/dpid/dpidrc.dist.in
	@${MV} ${WRKSRC}/src/keysrc ${WRKSRC}/src/keysrc.dist
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|dillorc|dillorc.dist|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|dpidrc|dpidrc.dist|g" ${WRKSRC}/dpid/Makefile.in
	@${REINPLACE_CMD} -e "s|keysrc|keysrc.dist|g" ${WRKSRC}/src/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-dist_docDATA||" ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.for f in dillorc dpidrc keysrc
. if !exists(${PREFIX}/etc/dillo/${f})
	${INSTALL_DATA} ${PREFIX}/etc/dillo/${f}.dist ${PREFIX}/etc/dillo/${f}
. endif
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
