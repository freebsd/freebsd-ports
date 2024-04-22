PORTNAME=	pload
DISTVERSION=	0.9.5
PORTREVISION=	7
CATEGORIES=	net sysutils
MASTER_SITES=	http://opal.com/src/pload/ LOCAL/pav

MAINTAINER=	fbsd@opal.com
COMMENT=	X11 program to display network traffic graphs
WWW=		https://opal.com/src/pload/

USES=		imake:env xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
HAS_CONFIGURE=	yes
LATE_INSTALL_ARGS=	install.man

PLIST_FILES=	bin/pload share/man/man1/pload.1.gz

.include <bsd.port.mk>
