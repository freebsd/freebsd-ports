# New ports collection makefile for:    gspdf
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gspdf
PORTVERSION=	0.1
CATEGORIES=	print
MASTER_SITES=	http://www.gnustep.it/enrico/gspdf/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Postscript and Pdf Viewer for GNUstep

WRKSRC=		${WRKDIR}/GSPdf
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
USE_GHOSTSCRIPT=	yes

.include <bsd.port.mk>
