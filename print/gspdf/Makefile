# New ports collection makefile for:    gspdf
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gspdf
PORTVERSION=	0.3
CATEGORIES=	print gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	GSPdf-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Postscript and Pdf Viewer for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GHOSTSCRIPT=	yes

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.include <bsd.port.mk>
