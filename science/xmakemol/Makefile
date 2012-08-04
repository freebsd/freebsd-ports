# New ports collection makefile for: xmakemol
# Date created:	8 June, 2001
# Whom:		Chi
# $FreeBSD$
#

PORTNAME=	xmakemol
PORTVERSION=	5.16
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Molecule Viewer Program Based on Motif Widget

USE_XORG=	xpm
USE_GL=		glut glw
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		xmakemol.1
PLIST_FILES=	bin/xmake_anim.pl \
		bin/xmakemol \
		%%DATADIR%%/elements
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
