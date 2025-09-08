PORTNAME=	signxml
PORTVERSION=	4.2.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python XML Signature and XAdES library
WWW=		https://xml-security.github.io/signxml/ \
		https://github.com/XML-Security/signxml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2023.11.17:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=5.2.1<7:devel/py-lxml5@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
