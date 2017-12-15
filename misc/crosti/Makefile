# $FreeBSD$

PORTNAME=	crosti
DISTVERSION=	1.13.3
DISTVERSIONSUFFIX=	-source
CATEGORIES=	misc
MASTER_SITES=	SF/crosti/crosti%20${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convert custom image to cross stitch design, edit stitch designs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		desktop-file-utils dos2unix qmake shared-mime-info zip
USE_GL=		gl
USE_QT5=	concurrent core gui printsupport svg widgets buildtools_build
DOS2UNIX_FILES=	${PORTNAME}.pro
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
