# $FreeBSD$

PORTNAME=	crosti
DISTVERSION=	1.14.0
DISTVERSIONSUFFIX=	-source
CATEGORIES=	misc
MASTER_SITES=	SF/crosti/crosti%20${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convert custom image to cross stitch design, edit stitch designs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl qmake qt:5 \
		shared-mime-info zip
DOS2UNIX_GLOB=	*.cpp *.csc *.h *.pro *.txt *.xml
USE_GL=		gl
USE_QT=		concurrent core gui printsupport svg widgets buildtools_build
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
