PORTNAME=	xlsfonts
PORTVERSION=	1.0.8
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Server font list displayer for X
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11

PLIST_FILES=	bin/xlsfonts share/man/man1/xlsfonts.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
