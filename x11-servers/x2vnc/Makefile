PORTNAME=	x2vnc
PORTVERSION=	1.7.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-servers
MASTER_SITES=	http://fredrik.hubbe.net/x2vnc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to link multiple X and VNC servers together
WWW=		https://fredrik.hubbe.net/x2vnc.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USES=		xorg
USE_XORG=	x11 xext xrandr xxf86dga ice xinerama xrandr xrender xscrnsaver sm

PLIST_FILES=	bin/x2vnc \
		share/man/man1/x2vnc.1.gz

.include <bsd.port.mk>
