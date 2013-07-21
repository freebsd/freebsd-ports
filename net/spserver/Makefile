# Created by: vanilla@
# $FreeBSD$

PORTNAME=	spserver
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A TCP server framework library written in C++ based on libevent

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	all build_openssl
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GNUTLS
#		MATRIXSSL	"Enable matrixssl support" off \
#		XYSSL		"Enable xyssl support" off

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATRIXSSL}
BUILD_DEPENDS=	${LOCALBASE}/lib/libmatrixsslstatic.a:${PORTSDIR}/security/matrixssl
ALL_TARGET+=	build_matrixssl
PLIST_SUB+=	WITH_MATRIXSSL=""
.else
PLIST_SUB+=	WITH_MATRIXSSL="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
ALL_TARGET+=	build_gnutls
PLIST_SUB+=	WITH_GNUTLS=""
.else
PLIST_SUB+=	WITH_GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MXYSSL}
BUILD_DEPENDS=	${LOCALBASE}/lib/libxyssl.a:${PORTSDIR}/security/xyssl
ALL_TARGET+=	build_xyssl
PLIST_SUB+=	WITH_XYSSL=""
.else
PLIST_SUB+=	WITH_XYSSL="@comment "
.endif

post-patch:
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/spserver/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/gnutls/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/matrixssl/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/openssl/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/xyssl/Makefile

do-install:
	@${MKDIR} ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/*.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/libspserver.so ${PREFIX}/lib/libspserver.so.1
	@${LN} -s ${PREFIX}/lib/libspserver.so.1 ${PREFIX}/lib/libspserver.so
	@${INSTALL} ${WRKSRC}/openssl/spopenssl.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/openssl/libspopenssl.so ${PREFIX}/lib/libspopenssl.so.1
	@${LN} -s ${PREFIX}/lib/libspopenssl.so.1 ${PREFIX}/lib/libspopenssl.so

.if ${PORT_OPTIONS:MGNUTLS}
	@${INSTALL} ${WRKSRC}/gnutls/spgnutls.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/gnutls/libspgnutls.so ${PREFIX}/lib/libspgnutls.so.1
	@${LN} -s ${PREFIX}/lib/libspgnutls.so.1 ${PREFIX}/lib/libspgnutls.so
.endif

.if ${PORT_OPTIONS:MMATRIXSSL}
	@${INSTALL} ${WRKSRC}/matrixssl/spmatrixssl.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/matrixssl/libspmatrixssl.so ${PREFIX}/lib/libspmatrixssl.so.1
	@${LN} -s ${PREFIX}/lib/libspmatrixssl.so.1 ${PREFIX}/lib/libspmatrixssl.so
.endif

.if ${PORT_OPTIONS:MXYSSL}
	@${INSTALL} ${WRKSRC}/xyssl/spxyssl.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/xyssl/libspxyssl.so ${PREFIX}/lib/libspxyssl.so.1
	@${LN} -s ${PREFIX}/lib/libspxyssl.so.1 ${PREFIX}/lib/libspxyssl.so
.endif

.include <bsd.port.mk>
