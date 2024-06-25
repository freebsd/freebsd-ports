PORTNAME=	mmg
PORTVERSION=	5.7.3
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bidimensional and tridimensional remeshing
WWW=		https://www.mmgtools.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git	\
		bash:shells/bash
LIB_DEPENDS=	libscotch.so:cad/scotch	\
		libElas.so:science/linearelasticity	\
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake:testing perl5 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	scripts/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	MmgTools

CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
