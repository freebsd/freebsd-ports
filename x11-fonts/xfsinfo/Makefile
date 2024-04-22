PORTNAME=	xfsinfo
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font server information utility
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 libfs

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/xfsinfo share/man/man1/xfsinfo.1.gz

.include <bsd.port.mk>
