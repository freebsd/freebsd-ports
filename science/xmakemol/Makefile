# Created by: Chi
# $FreeBSD$

PORTNAME=	xmakemol
PORTVERSION=	5.16
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Molecule Viewer Program Based on Motif Widget

USES=		gmake motif
USE_XORG=	xpm
USE_GL=		glut glw
GNU_CONFIGURE=	yes

MAN1=		xmakemol.1
PLIST_FILES=	bin/xmake_anim.pl \
		bin/xmakemol \
		%%DATADIR%%/elements
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
