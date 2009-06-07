# New ports collection makefile for:   dillo
# Date created:        28 August 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$

PORTNAME=	dillo
PORTVERSION=	2.0
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/

MAINTAINER=	bf1783@gmail.com
COMMENT=	A fast, small graphical Web browser built upon fltk2

BUILD_DEPENDS=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2
RUN_DEPENDS=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2 \
		wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PORTDOCS=	*
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
CONFIGURE_ARGS+= --enable-cookies
.else
CONFIGURE_ARGS+= --disable-cookies
.endif

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-gprof --enable-rtfl
.else
CONFIGURE_ARGS+=	--disable-gprof --disable-rtfl
.endif

.ifdef(WITH_IPV6)
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

.ifdef(WITH_SSL)
CONFIGURE_ARGS+= --enable-ssl
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+= --disable-ssl
.endif

.ifdef(WITH_THREADED_DNS)
CONFIGURE_ARGS+= --enable-threaded-dns
CFLAGS+=	${PTHREAD_CFLAGS}
.else
CONFIGURE_ARGS+= --disable-threaded-dns
.endif

post-patch:
.ifdef(WITH_SSL)
	${REINPLACE_CMD} -e '/^#undef ENABLE_SSL/d' ${WRKSRC}/dpi/https.c
.endif
	@${MV} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.dist
	@${REINPLACE_CMD} -e "s|dillorc|dillorc.dist|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|dpidrc|dpidrc.dist|g" ${WRKSRC}/dpid/Makefile.in

post-install:
.if !exists(${PREFIX}/etc/dillorc)
	${INSTALL_DATA} ${PREFIX}/etc/dillorc.dist ${PREFIX}/etc/dillorc
.endif
.if !exists(${PREFIX}/etc/dpidrc)
	${INSTALL_DATA} ${PREFIX}/etc/dpidrc.dist ${PREFIX}/etc/dpidrc
.endif
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
