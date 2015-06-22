# $FreeBSD$

PORTNAME=	gspdf
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	print gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GSPdf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postscript and Pdf Viewer for GNUstep

USES=		gnustep
USE_GNUSTEP=	back build
USE_GHOSTSCRIPT=	yes

MAKE_ENV=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GSPdf.app/GSPdf

.include <bsd.port.mk>
