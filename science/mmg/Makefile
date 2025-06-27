PORTNAME=	mmg
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.3
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bidimensional and tridimensional remeshing
WWW=		https://www.mmgtools.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libscotch.so:cad/scotch	\
		libElas.so:science/linearelasticity \
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	scripts/*.pl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MmgTools

CMAKE_ON=	BUILD_SHARED_LIBS

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
