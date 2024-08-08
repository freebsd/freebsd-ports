PORTNAME=	django-auth-ldap
PORTVERSION=	4.8.0
CATEGORIES=	www security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	LDAP integration for django.contrib.auth
WWW=		https://github.com/django-auth-ldap/django-auth-ldap

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=3.2:www/py-django50@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>=3.1:net/py-python-ldap@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

post-build-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html ${WRKSRC}/docs ${WRKSRC}/build/sphinx/html

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
