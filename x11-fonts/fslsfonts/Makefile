PORTNAME=	fslsfonts
DISTVERSION=	1.0.7
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	List fonts served by the X font server
WWW=		https://gitlab.freedesktop.org/xorg/app/fslsfonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	libfs xorgproto

PLIST_FILES=	bin/fslsfonts share/man/man1/fslsfonts.1.gz

.include <bsd.port.mk>
