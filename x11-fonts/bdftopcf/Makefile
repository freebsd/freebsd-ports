PORTNAME=	bdftopcf
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Convert X font from BDF to PCF
WWW=		https://www.x.org/archive/X11R6.8.1/doc/bdftopcf.1.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase xorg xorg-cat:app

USE_XORG=	xorgproto

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/bdftopcf share/man/man1/bdftopcf.1.gz

.include <bsd.port.mk>
