PORTNAME=	simple-fb2-reader
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple FB2 format book reader

LICENSE=	GPLv3+

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		cmake desktop-file-utils gettext-runtime gnome pkgconfig \
		shared-mime-info sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	Cactus64k
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2

.include <bsd.port.mk>
