PORTNAME=	ttp-templates
DISTVERSION=	0.3.6
CATEGORIES=	textproc net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ttp_templates-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Template Text Parser templates collections
WWW=		https://github.com/dmulyalin/ttp_templates

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ttp>=0.6.0:textproc/py-ttp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
