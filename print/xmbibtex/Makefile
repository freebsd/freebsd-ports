# New ports collection makefile for:	xmbibtex
# Date created:				06 Nov 1997
# Whom:					Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmbibtex
PORTVERSION=	1.7
CATEGORIES=	print databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/tex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A reference manager based on the BibTeX file format

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_MOTIF=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/xmbibtex lib/X11/app-defaults/XmBibTeX

.include <bsd.port.mk>
