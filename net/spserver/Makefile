# Created by: vanilla@
# $FreeBSD$

PORTNAME=	spserver
PORTVERSION=	0.9.5
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	TCP server framework library written in C++ based on libevent

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
USES=		gmake
ALL_TARGET=	all build_openssl
MAKE_JOBS_UNSAFE=	yes

BROKEN=		Misuse libevent API
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-02-28

OPTIONS_DEFINE=	GNUTLS
#		MATRIXSSL	"Enable matrixssl support" off

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATRIXSSL}
BUILD_DEPENDS=	${LOCALBASE}/lib/libmatrixsslstatic.a:${PORTSDIR}/security/matrixssl
ALL_TARGET+=	build_matrixssl
PLIST_SUB+=	WITH_MATRIXSSL=""
.else
PLIST_SUB+=	WITH_MATRIXSSL="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
ALL_TARGET+=	build_gnutls
PLIST_SUB+=	WITH_GNUTLS=""
.else
PLIST_SUB+=	WITH_GNUTLS="@comment "
.endif

post-patch:
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/spserver/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/gnutls/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/matrixssl/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/openssl/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/xyssl/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/*.hpp ${STAGEDIR}/${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/libspserver.so ${STAGEDIR}/${PREFIX}/lib/libspserver.so.1
	@${LN} -s ${PREFIX}/lib/libspserver.so.1 ${STAGEDIR}/${PREFIX}/lib/libspserver.so
	@${INSTALL} ${WRKSRC}/openssl/spopenssl.hpp ${STAGEDIR}/${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/openssl/libspopenssl.so ${STAGEDIR}/${PREFIX}/lib/libspopenssl.so.1
	@${LN} -s ${PREFIX}/lib/libspopenssl.so.1 ${STAGEDIR}/${PREFIX}/lib/libspopenssl.so

.if ${PORT_OPTIONS:MGNUTLS}
	@${INSTALL} ${WRKSRC}/gnutls/spgnutls.hpp ${STAGEDIR}/${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/gnutls/libspgnutls.so ${STAGEDIR}/${PREFIX}/lib/libspgnutls.so.1
	@${LN} -s ${PREFIX}/lib/libspgnutls.so.1 ${STAGEDIR}/${PREFIX}/lib/libspgnutls.so
.endif

.if ${PORT_OPTIONS:MMATRIXSSL}
	@${INSTALL} ${WRKSRC}/matrixssl/spmatrixssl.hpp ${STAGEDIR}/${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/matrixssl/libspmatrixssl.so ${STAGEDIR}/${PREFIX}/lib/libspmatrixssl.so.1
	@${LN} -s ${PREFIX}/lib/libspmatrixssl.so.1 ${STAGEDIR}/${PREFIX}/lib/libspmatrixssl.so
.endif

.include <bsd.port.mk>
