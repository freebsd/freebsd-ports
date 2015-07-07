# $FreeBSD$

PORTNAME=	msx264
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	SAVANNAH/linphone/plugins/sources/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Mediastreamer plugin for H264 encoding

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libx264.so:${PORTSDIR}/multimedia/libx264

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig

.include <bsd.port.mk>
