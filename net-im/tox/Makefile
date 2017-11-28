# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxcore
PORTVERSION=	0.1.8
PORTREVISION=	3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:devel/check
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libsndfile.so:audio/libsndfile		\
		libsodium.so:security/libsodium		\
		libopencv_core.so:graphics/opencv-core	\
		libopus.so:audio/opus			\
		libconfig.so:devel/libconfig
TEST_DEPENDS=	${LOCALBASE}/lib/libmsgpackc.so:devel/msgpack	\
		${LOCALBASE}/lib/libportaudio.so:audio/portaudio

USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_PROJECT=	c-toxcore

USES=		cmake compiler:c11 libtool pathfix pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	VER=${PORTVERSION:C/0.//}.0 SO=1

OPTIONS_DEFINE=		DAEMON
OPTIONS_SUB=		yes

DAEMON_DESC=		Bootstrap daemon
DAEMON_CMAKE_ON=	-DBOOTSTRAP_DAEMON=on
DAEMON_LIB_DEPENDS=	libconfig.so:devel/libconfig

TEST_TARGET=	test

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
	${INSTALL_PROGRAM} ${WRKSRC}/tox-bootstrapd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/other/bootstrap_daemon/tox-bootstrapd.conf	\
		${STAGEDIR}${PREFIX}/etc/tox-bootstrapd.conf.sample
	${MKDIR} ${STAGEDIR}${KEYS_DIR}
	${MKDIR} ${STAGEDIR}${PID_DIR}
.endif

.include <bsd.port.mk>
