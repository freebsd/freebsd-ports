# Created by: Conrad Sabatier <conrads@home.com>
# $FreeBSD$

PORTNAME=	xless
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	XCONTRIB/applications \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based viewer for text files

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAKE_ARGS=	MAKE="${MAKE_CMD}"

PLIST_FILES=	bin/xless lib/X11/xless.help lib/X11/app-defaults/XLess \
		lib/X11/app-defaults/XLess-color man/man1/xless.1.gz

.include <bsd.port.mk>
