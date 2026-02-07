PORTNAME=	gspdf
PORTVERSION=	0.5
PORTREVISION=	13
CATEGORIES=	print gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GSPdf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postscript and Pdf Viewer for GNUstep
WWW=		https://gap.nongnu.org/gspdf/index.html

USES=		ghostscript gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GSPdf.app/GSPdf

.include <bsd.port.mk>
