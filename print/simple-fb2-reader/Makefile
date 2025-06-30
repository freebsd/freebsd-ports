PORTNAME=	simple-fb2-reader
PORTVERSION=	1.1.3
PORTREVISION=	6
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple FB2 format book reader
WWW=		https://github.com/Cactus64k/simple-fb2-reader

LICENSE=	GPLv3+

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		cmake desktop-file-utils gettext-runtime gnome pkgconfig \
		shared-mime-info sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	Cactus64k
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2

.include <bsd.port.mk>
