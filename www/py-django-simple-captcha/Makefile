PORTNAME=	django-simple-captcha
PORTVERSION=	0.6.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_simple_captcha-${PORTVERSION}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Simple, yet powerful, Django captcha application
WWW=		https://pypi.org/project/django-simple-captcha/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-ranged-response>=0.2.0<0.2.0_99:www/py-django-ranged-response@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.2.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-book-theme>0:textproc/py-sphinx-book-theme@${PY_FLAVOR}

post-build-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
		-d ${WRKDIR} -b html ${WRKSRC}/docs/ ${WRKSRC}/build/sphinx/html

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
