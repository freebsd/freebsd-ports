PORTNAME=	mrchem
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	science python # chemistry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MultiResolution Chemistry
WWW=		https://github.com/MRChemSoft/mrchem

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	mrchem>0:science/mrchem

USES=		cmake python shebangfix
USE_PYTHON=	concurrent flavors

USE_GITHUB=	yes
GH_ACCOUNT=	MRChemSoft

SHEBANG_FILES=	mrchem.in ../tests/*/test

WRKSRC_SUBDIR=	python

NO_ARCH=	yes

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DCMAKE_INSTALL_BINDIR=bin \
		-DPYMOD_INSTALL_LIBDIR=${PYTHON_SITELIBDIR:S;${PREFIX}/lib/;;}

post-install:
	@${RMDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mrchem/input_parser/docs

# tests should be run in science/mrchem

.include <bsd.port.mk>
