# $FreeBSD$

PORTNAME=	dalton
DISTVERSION=	2016.2
PORTREVISION=	2
CATEGORIES=	science

PATCH_SITES=	https://gitlab.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	b838ac7be3bba7fe9bc0fdf81b20cde37a38f3c0.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Powerful molecular electronic structure program for quantum chemistry

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:outsource,noninja fortran python:build shebangfix
SHEBANG_FILES=	dalton.in
USE_GITLAB=	yes
GL_COMMIT=	130ffaa0613bb3af6cac766fc8183d6df7d68917
USE_GITHUB=	nodefault

GL_TUPLE=	bingao:gen1int:70d10a37390f4e42a90b2951cb3fec3e9a870d13:gen1int/external/gen1int \
		dalton:efs:ffc1a2f137fa6e322143bf84be724d9b815e637b:efs/external/efs \
		pe-software:pelib-public:f679dfbc5d16cb91cb964320782d02fdb011b1f6:pelib/external/pelib
GH_TUPLE=	cstein:qfitlib:d931560:qfitlib/external/qfitlib \
		dftlibs:xcfun:177fcd96:xcfun/external/xcfun \
		dftlibs:xcint:2d1496f5:xcint/external/xcint

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' 's|%%SCRIPT_DIR%%|${DATADIR}|; s|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MV} ${STAGEDIR}${DATADIR}/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
