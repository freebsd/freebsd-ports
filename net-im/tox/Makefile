# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxcore
PORTVERSION=	0.141026
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:${PORTSDIR}/devel/libcheck
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus		\
		libv4l2.so:${PORTSDIR}/multimedia/libv4l	\
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9c480ac

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
CONFIGURE_ARGS=	--enable-tests
USES=		libtool openal:soft pathfix pkgconfig
USE_SDL=	yes
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=		DAEMON
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SODIUM NACL
OPTIONS_DEFAULT=	SODIUM
OPTIONS_SUB=		yes

SODIUM_DESC=		Prefer libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

NACL_DESC=		Prefer NaCl
NACL_CONFIGURE_ENABLE=	nacl
NACL_CONFIGURE_ON=	--with-nacl-libs=${LOCALBASE}/lib
NACL_BUILD_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl
NACL_RUN_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl

DAEMON_DESC=		Bootstrap daemon
DAEMON_CONFIGURE_ENABLE=daemon
DAEMON_LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
BROKEN_i386=	'__stack_chk_fail_local' isn't defined
.endif

.if ${PORT_OPTIONS:MDAEMON}
USERS=	toxdht
USE_RC_SUBR=	tox-bootstrapd
SUB_LIST=	TOXDHT=${USERS}
PLIST_SUB+=	TOXDHT=${USERS}
KEYS_DIR=	/var/lib/tox-bootstrapd
PID_DIR=	/var/run/tox-bootstrapd
PKGMESSAGE=	${PKGDIR}/pkg-message.daemon
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac

post-install:
.if ${PORT_OPTIONS:MDAEMON}
	${INSTALL_DATA} ${WRKSRC}/other/bootstrap_daemon/tox-bootstrapd.conf	\
		${STAGEDIR}${PREFIX}/etc/tox-bootstrapd.conf.sample
	${MKDIR} ${STAGEDIR}${KEYS_DIR}
	${MKDIR} ${STAGEDIR}${PID_DIR}
.endif

.include <bsd.port.mk>
