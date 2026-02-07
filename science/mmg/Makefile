PORTNAME=	mmg
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.0
CATEGORIES=	science

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Bidimensional and tridimensional remeshing
WWW=		https://www.mmgtools.org/ \
		https://github.com/MmgTools/mmg/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libElas.so:science/linearelasticity \
		libscotch.so:cad/scotch \
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	MmgTools
USE_LDCONFIG=	yes
USE_PERL5=	build

SHEBANG_FILES=	scripts/*.pl scripts/*.sh

CMAKE_ON=	BUILD_SHARED_LIBS

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
