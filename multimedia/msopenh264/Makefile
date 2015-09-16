# $FreeBSD$

PORTNAME=	msopenh264
PORTVERSION=	1.0.0
CATEGORIES=	multimedia net
MASTER_SITES=	SAVANNAH/linphone/plugins/sources/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Mediastreamer plugin for H264 encoding/decoding

LIB_DEPENDS=	libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libopenh264.so:${PORTSDIR}/multimedia/openh264

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
