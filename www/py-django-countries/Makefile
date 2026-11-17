PORTNAME=	django-countries
DISTVERSION=	9.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_countries-${DISTVERSION}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Provides country choices for use with django
WWW=		https://github.com/SmileyChris/django-countries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.6:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>0:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=4.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	django_countries/data.py django_countries/makesprite.py

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|uv_build>=0.9.6,<0.10.0|uv_build>=0.9.6|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
