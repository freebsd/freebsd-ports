# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxcore
PORTVERSION=	0.160924
PORTREVISION=	3
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:devel/libcheck
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libopus.so:audio/opus

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_TAGNAME=	161ab46

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tests
USES=		autoreconf compiler:c11 libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=		DAEMON
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SODIUM NACL
OPTIONS_DEFAULT=	SODIUM
OPTIONS_SUB=		yes

SODIUM_DESC=		Prefer libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:security/libsodium

NACL_DESC=		Prefer NaCl
NACL_CONFIGURE_ENABLE=	nacl
NACL_CONFIGURE_ON=	--with-nacl-libs=${LOCALBASE}/lib
NACL_BUILD_DEPENDS=	${LOCALBASE}/lib/libnacl.a:security/nacl
NACL_RUN_DEPENDS=	${LOCALBASE}/lib/libnacl.a:security/nacl

DAEMON_DESC=		Bootstrap daemon
DAEMON_CONFIGURE_ENABLE=daemon
DAEMON_LIB_DEPENDS=	libconfig.so:devel/libconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDAEMON}
USERS=	toxdht
USE_RC_SUBR=	tox-bootstrapd
SUB_LIST=	TOXDHT=${USERS}
PLIST_SUB+=	TOXDHT=${USERS}
KEYS_DIR=	/var/lib/tox-bootstrapd
PID_DIR=	/var/run/tox-bootstrapd
PKGMESSAGE=	${PKGDIR}/pkg-message.daemon
.endif

pre-everything::
.if ${PORT_OPTIONS:MNACL}
	@${ECHO_CMD}
	@${ECHO_CMD} "Warning: building toxcore against NaCl is not supported by some clients (e.g. qTox)!"
	@${ECHO_CMD}
.endif

pre-configure:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac

post-install:
.if ${PORT_OPTIONS:MDAEMON}
	${INSTALL_DATA} ${WRKSRC}/other/bootstrap_daemon/tox-bootstrapd.conf	\
		${STAGEDIR}${PREFIX}/etc/tox-bootstrapd.conf.sample
	${MKDIR} ${STAGEDIR}${KEYS_DIR}
	${MKDIR} ${STAGEDIR}${PID_DIR}
.endif

.include <bsd.port.mk>
