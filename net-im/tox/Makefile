PORTNAME=	toxcore
PORTVERSION=	0.2.19
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger
WWW=		https://tox.chat/

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:devel/check			\
		gtest:sysutils/coreutils
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libsndfile.so:audio/libsndfile		\
		libportaudio.so:audio/portaudio		\
		libsodium.so:security/libsodium		\
		libopus.so:audio/opus			\
		libconfig.so:devel/libconfig
TEST_DEPENDS=	opencv_visualisation:graphics/opencv
#TEST_DEPENDS=	libopencv_core.so:graphics/opencv

USE_GITHUB=	yes
GH_ACCOUNT=	TokTok camgunz:cmp
GH_PROJECT=	c-toxcore cmp:cmp
GH_TAGNAME=	643e6a62d4eb0ec2277de269cda33da02cba2756:cmp
GH_SUBDIR=	third_party/cmp:cmp

CPE_VENDOR=	toktok

USES=		cmake cpe pathfix pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	VER=${PORTVERSION:C/0.//}.0 SO=2

OPTIONS_DEFINE=		DAEMON TEST
OPTIONS_SUB=		yes

DAEMON_DESC=		Bootstrap daemon
DAEMON_CMAKE_ON=	-DBOOTSTRAP_DAEMON=on
DAEMON_LIB_DEPENDS=	libconfig.so:devel/libconfig

TEST_CMAKE_ON=		-DAUTOTEST=on
TEST_TARGET=		test

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
	${INSTALL_DATA} ${WRKSRC}/other/bootstrap_daemon/tox-bootstrapd.conf	\
		${STAGEDIR}${PREFIX}/etc/tox-bootstrapd.conf.sample
	${MKDIR} ${STAGEDIR}${KEYS_DIR}
	${MKDIR} ${STAGEDIR}${PID_DIR}
.endif

.include <bsd.port.mk>
