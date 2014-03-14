# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	ProjectTox-Core
PORTVERSION=	0.140314
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:${PORTSDIR}/devel/libcheck
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	ProjectTox-Core
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	3acf43b

USE_AUTOTOOLS=	automake autoconf libtoolize
USES=		pkgconfig
USE_LDCONFIG=	yes

OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SODIUM NACL
OPTIONS_DEFINE=		PHONE
OPTIONS_DEFAULT=	PHONE SODIUM

PHONE_DESC=		Enable phone test
PHONE_CONFIGURE_ENABLE=	phone
PHONE_LIB_DEPENDS=	libopenal.so.1:${PORTSDIR}/audio/openal-soft	\
			libv4l2.so:${PORTSDIR}/multimedia/libv4l	\
			libswscale.so:${PORTSDIR}/multimedia/ffmpeg
PHONE_USE=		SDL=sdl

SODIUM_DESC=		Prefer libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

NACL_DESC=		Prefer NaCl
NACL_CONFIGURE_ENABLE=	nacl
NACL_BUILD_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl
NACL_RUN_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
BROKEN_i386=	`__stack_chk_fail_local' isn't defined
.endif

.if ${PORT_OPTIONS:MNACL}
CONFIGURE_ARGS+=	--with-nacl-libs=${LOCALBASE}/lib
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
