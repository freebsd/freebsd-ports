PORTNAME=	dftbplus
DISTVERSION=	25.1
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFTB+: Package for performing fast atomistic simulations
WWW=		https://dftbplus.org/

LICENSE=	GPLv3 # main code is under LGPL3+, the bundled dftd3-lib is under GPLv1+, this makes the result GPLv3 (based on https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	dftbplus>0:science/dftbplus

USES=		compiler:gcc-c++11-lib fortran python shebangfix

SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
USE_PYTHON=	pep517 autoplist

WRKSRC_SUBDIR=	tools/pythonapi

NO_ARCH=	yes

post-patch: # patch pyproject.toml to use real version instead of 0.1
	@${REINPLACE_CMD} -e 's/^version = "0.1"/version = "${DISTVERSION}"/' ${WRKSRC}/pyproject.toml


.include <bsd.port.mk>
