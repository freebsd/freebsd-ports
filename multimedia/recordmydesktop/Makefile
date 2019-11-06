# $FreeBSD$

PORTNAME=	recordmydesktop
DISTVERSION=	0.3.8.1
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Record desktop sessions to an Ogg-Theora-Vorbis file

LIB_DEPENDS=	libtheora.so:multimedia/libtheora \
		libjack.so:audio/jack

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-oss=yes \
			--enable-jack=yes

USES=		xorg
USE_XORG=	ice sm x11 xext xorgproto xfixes xdamage
PLIST_FILES=	bin/recordmydesktop man/man1/recordmydesktop.1.gz

.include <bsd.port.mk>
