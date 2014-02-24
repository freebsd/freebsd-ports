# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	ProjectTox-Core
PORTVERSION=	0.140222
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:${PORTSDIR}/devel/libcheck
LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium	\
		libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	ProjectTox-Core
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	f219fb4

USE_AUTOTOOLS=	automake autoconf libtoolize
USES=		pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PHONE
OPTIONS_DEFAULT=PHONE

PHONE_DESC=		Enable phone test
PHONE_CONFIGURE_ENABLE=	phone
PHONE_LIB_DEPENDS=	libopenal.so:${PORTSDIR}/audio/openal		\
			libv4l2.so:${PORTSDIR}/multimedia/libv4l	\
			libswscale.so:${PORTSDIR}/multimedia/ffmpeg
PHONE_USE=		SDL=sdl

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
