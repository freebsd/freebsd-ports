# New ports collection makefile for:   dillo
# Date created:        28 August 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$

PORTNAME=	dillo
PORTVERSION=	2.2
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/

MAINTAINER=	bf1783@gmail.com
COMMENT=	A fast, small graphical Web browser built upon fltk2

BUILD_DEPENDS=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2
RUN_DEPENDS=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2 \
		wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
.ifndef(NO_INSTALL_MANPAGES)
MAN1=		dillo.1
.endif
.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec
CONFLICTS=	dillo-i18n-[0-9]* \
		dillo-0*
LATEST_LINK=	dillo2

OPTIONS=	COOKIES 	"Enable cookies" On \
		DEBUG		"Enable profiling and extra logging" Off \
		IPV6		"Enable ipv6"	On \
		SSL		"Enable (experimental) https support" On \
		THREADED_DNS	"Enable re-entrant resolver library" On

.include <bsd.port.pre.mk>

.ifdef(WITH_COOKIES)
CONFIGURE_ARGS+=	--enable-cookies
.else
CONFIGURE_ARGS+=	--disable-cookies
.endif

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-gprof --enable-rtfl
.else
CONFIGURE_ARGS+=	--disable-gprof --disable-rtfl
.endif

.ifdef(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.ifdef(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.ifdef(WITH_THREADED_DNS)
CONFIGURE_ARGS+=	--enable-threaded-dns
CFLAGS+=	${PTHREAD_CFLAGS}
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
.ifdef(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-man||" ${WRKSRC}/doc/Makefile.in
.endif
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-dist_docDATA||" ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.for _F in dillorc dpidrc keysrc
. if !exists(${PREFIX}/etc/dillo/${_F})
	${INSTALL_DATA} ${PREFIX}/etc/dillo/${_F}.dist ${PREFIX}/etc/dillo/${_F}
. endif
.endfor
.ifndef(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
