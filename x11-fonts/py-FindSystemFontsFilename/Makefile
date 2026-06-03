PORTNAME=	FindSystemFontsFilename
DISTVERSION=	0.3.3
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Find the system fonts filename
WWW=		https://github.com/moi15moi/FindSystemFontsFilename/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# fix build with devel/py-setuptools < 77.0.0
post-patch:
	@${REINPLACE_CMD} -e 's,^\(license = \)\("MIT"\),\1{ text = \2 },1' \
		-e 's,\(setuptools>=\)77.0.0,\163.1.0,1' \
		-e '/^license-files/d' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
