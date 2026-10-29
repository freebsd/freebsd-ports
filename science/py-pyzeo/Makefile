PORTNAME=	pyzeo
DISTVERSION=	0.2.0
CATEGORIES=	science python # chemistry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to Zeo++
WWW=		https://github.com/nomad-coe/pyzeo \
		https://www.zeoplusplus.org/

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/src/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	nomad-coe
GH_TAGNAME=	1524fea78ec212fa7bf3b417ff96f5c1c7cf09ce # the v0.2.0 tag points to an older commit

# fused multiply-add contraction (default on aarch64) breaks the Voronoi volume check
CFLAGS+=	-ffp-contract=off

# test_areavol_mass and test_surface_area_mass compare Monte Carlo results driven by
# rand() with values precomputed using glibc's rand() sequence, which differs from FreeBSD libc
TEST_ARGS=	--disable-plugin-autoload \
		--ignore=test_areavol_mass.py --ignore=test_surface_area_mass.py
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyzeo/extension*.so

# tests as of 0.2.0: 15 passed in 0.93s

.include <bsd.port.mk>
