# New ports collection makefile for: xmakemol
# Date created:	8 June, 2001
# Whom:		Chi
# $FreeBSD$
#

PORTNAME=	xmakemol
PORTVERSION=	5.12
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chizhang@uchicago.edu
COMMENT=	Molecule Viewer Program Based on Motif Widget

USE_XLIB=	yes
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		xmakemol.1

pre-configure:
	cd ${WRKSRC}; ${CHMOD} 755 config.guess config.sub configure install-sh missing mkinstalldirs

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xmakemol

.include <bsd.port.mk>
