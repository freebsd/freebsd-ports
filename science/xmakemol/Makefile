# Created by: Chi
# $FreeBSD$

PORTNAME=	xmakemol
PORTVERSION=	5.16
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Molecule Viewer Program Based on Motif Widget

USES=		gmake motif shebangfix
USE_XORG=	xpm
USE_GL=		glut glw
GNU_CONFIGURE=	yes
SHEBANG_FILES=	xmake_anim.pl

PLIST_FILES=	bin/xmake_anim.pl \
		bin/xmakemol \
		man/man1/xmakemol.1.gz \
		%%DATADIR%%/elements
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
