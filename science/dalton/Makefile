# $FreeBSD$

PORTNAME=	dalton
DISTVERSION=	2018.2
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Powerful molecular electronic structure program for quantum chemistry

LICENSE=	LGPL21

LIB_DEPENDS=	liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:noninja fortran python:build shebangfix
SHEBANG_FILES=	dalton.in
USE_GITLAB=	yes
GL_COMMIT=	4aa945ecd235fbf67ed0c1609617c553ef40be89
USE_GITHUB=	nodefault

GL_TUPLE=	bingao:gen1int:1e4148ecd676761b3399801acba443925a1fee6b:gen1int/external/gen1int \
		dalton:efs:ffc1a2f137fa6e322143bf84be724d9b815e637b:efs/external/efs \
		pe-software:pelib-public:ba0ba35e9d8f5663f320fb3de6010fb66106ed80:pelib/external/pelib
GH_TUPLE=	cstein:qfitlib:fdf3f38:qfitlib/external/qfitlib \
		dftlibs:xcfun:177fcd96:xcfun/external/xcfun \
		dftlibs:xcint:2d1496f5:xcint/external/xcint

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' 's|%%SCRIPT_DIR%%|${DATADIR}|; s|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MV} ${STAGEDIR}${DATADIR}/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/
	@cd ${STAGEDIR}${DATADIR} && ${RM} -r tools/CMakeFiles tools/Makefile tools/cmake_install.cmake

.include <bsd.port.mk>
