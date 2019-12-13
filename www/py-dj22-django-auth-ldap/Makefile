# Created by: Alexander Kriventsov <avk@vl.ru>
# $FreeBSD$

PORTNAME=	django-auth-ldap
PORTVERSION=	2.1.0
CATEGORIES=	www security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	LDAP integration for django.contrib.auth

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=3.1:net/py-ldap@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
PORTDOCS=	*
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-auth-ldap \
			${PYTHON_PKGNAMEPREFIX}dj21-django-auth-ldap

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
 		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
