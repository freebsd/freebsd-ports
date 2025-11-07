PORTNAME=	toxcore
DISTVERSION=	0.2.21
PORTEPOCH=	1
CATEGORIES=	net-im net-p2p
MASTER_SITES=	https://github.com/TokTok/c-${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	c-${PORTNAME}-v${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger
WWW=		https://tox.chat/ \
		https://github.com/TokTok/c-toxcore/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopus.so:audio/opus \
		libsodium.so:security/libsodium \
		libvpx.so:multimedia/libvpx
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang cpe pathfix pkgconfig tar:xz
CPE_VENDOR=	toktok
PATHFIX_CMAKELISTSTXT=	ModulePackage.cmake
USE_LDCONFIG=	yes

CMAKE_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GTest \
		UNITTEST
CMAKE_TESTING_ON=	UNITTEST
CMAKE_TESTING_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GTest
# AUTOTEST(s) are broken...

NO_WRKSUBDIR=	yes

PLIST_SUB=	VER=${DISTVERSION:C/0.//}.0 SO=2

OPTIONS_DEFINE=	DAEMON
OPTIONS_SUB=	yes

DAEMON_DESC=	Bootstrap daemon

DAEMON_LIB_DEPENDS=	libconfig.so:devel/libconfig
DAEMON_CMAKE_BOOL=	BOOTSTRAP_DAEMON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDAEMON}
USERS=		toxdht
USE_RC_SUBR=	tox-bootstrapd
SUB_LIST=	TOXDHT=${USERS}
PLIST_SUB+=	TOXDHT=${USERS}
KEYS_DIR=	/var/lib/tox-bootstrapd
PID_DIR=	/var/run/tox-bootstrapd
PKGMESSAGE=	${PKGDIR}/pkg-message.daemon
.endif

post-install:
.if ${PORT_OPTIONS:MDAEMON}
	${INSTALL_DATA} ${WRKSRC}/other/bootstrap_daemon/tox-bootstrapd.conf \
		${STAGEDIR}${PREFIX}/etc/tox-bootstrapd.conf.sample
	${MKDIR} ${STAGEDIR}${KEYS_DIR} \
		 ${STAGEDIR}${PID_DIR}
.endif

.include <bsd.port.mk>
