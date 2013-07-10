# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmbibtex
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	print databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/tex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference manager based on the BibTeX file format

WRKSRC_SUBDIR=	src

USES=		imake motif
USE_XORG=	ice sm x11 xext xmu xp xt xpm
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/xmbibtex lib/X11/app-defaults/XmBibTeX

post-configure:
	@${REINPLACE_CMD} -e 's,(CCLINK,(CXXLINK, ; s,/usr/local,${PREFIX},' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
