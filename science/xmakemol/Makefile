# New ports collection makefile for: xmakemol
# Date created:	8 June, 2001
# Whom:		Chi
# $FreeBSD$
#

PORTNAME=	xmakemol
PORTVERSION=	4.40
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://vegemite.chem.nottingham.ac.uk/~xmakemol/dists/

MAINTAINER=	chizhang@uchicago.edu
COMMENT=	Molecule Viewer Program Based on Motif Widget

USE_XLIB=	yes
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
pre-configure:
	cd ${WRKSRC}; ${CHMOD} 755 config.guess config.sub configure install-sh missing mkinstalldirs

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xmakemol
.include <bsd.port.post.mk>
