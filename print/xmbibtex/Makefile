PORTNAME=	xmbibtex
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	print databases
MASTER_SITES=	SUNSITE/apps/tex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference manager based on the BibTeX file format

USES=		imake:noman motif xorg
USE_CXXSTD=	c++14
USE_XORG=	ice sm x11 xext xmu xt xpm

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/xmbibtex lib/X11/app-defaults/XmBibTeX

.include <bsd.port.mk>
