PORTNAME=	molsketch
DISTVERSION=	0.8.2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/Molsketch/
DISTNAME=	Molsketch-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D molecule editor
WWW=		https://molsketch.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		cmake compiler:c++20-lang desktop-file-utils gl localbase:ldflags \
		pkgconfig qt:6 shared-mime-info # build fails with ninja, see https://sourceforge.net/p/molsketch/bugs/41/
USE_QT=		base svg tools:build
USE_LDCONFIG=	${PREFIX}/lib/molsketch
USE_GL=		gl opengl

CMAKE_ARGS=	-DMSK_PREFIX:STRING=${PREFIX}
CMAKE_ON=	MSK_QT6

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/Molsketch-${DISTVERSION}

PORTDOCS=	*

.include <bsd.port.mk>
