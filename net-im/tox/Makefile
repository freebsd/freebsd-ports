# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxcore
PORTVERSION=	0.1.2
PORTEPOCH=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:devel/libcheck
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libmsgpackc.so:devel/msgpack		\
		libsndfile.so:audio/libsndfile		\
		libsodium.so:security/libsodium		\
		libportaudio.so:audio/portaudio		\
		libopencv_core.so:graphics/opencv2-core	\
		libopus.so:audio/opus

USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_PROJECT=	c-toxcore
GH_TAGNAME=	v${PORTVERSION}

USES=		cmake compiler:c11 libtool pathfix pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DAEMON
OPTIONS_SUB=		yes

DAEMON_DESC=		Bootstrap daemon
DAEMON_CMAKE_ON=	-DBOOTSTRAP_DAEMON=on
DAEMON_LIB_DEPENDS=	libconfig.so:devel/libconfig

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
