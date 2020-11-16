# $FreeBSD$

PORTNAME=	dalton
DISTVERSION=	2020.0
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
GL_COMMIT=	66052b3af5ea7225e31178bf9a8b031913c72190
GL_TUPLE=	bingao:gen1int:1e4148ecd676761b3399801acba443925a1fee6b:gen1int/external/gen1int \
		pe-software:pelib-public:cf49a6e04fdca09af6245fb68a36d20b68552ace:pelib/external/pelib

USE_GITHUB=	nodefault
GH_TUPLE=	cstein:qfitlib:1acdc9863fdeae2cdbc7f5a599413257a095b8ad:qfitlib/external/qfitlib

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' 's|%%SCRIPT_DIR%%|${DATADIR}|; s|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MV} ${STAGEDIR}${DATADIR}/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/
	@cd ${STAGEDIR}${DATADIR}/tools && ${STRIP_CMD} aces2dalton distances FChk2HES labread xyz2dalton
	@cd ${STAGEDIR}${DATADIR} && ${RM} -r tools/CMakeFiles tools/Makefile tools/cmake_install.cmake

.include <bsd.port.mk>
