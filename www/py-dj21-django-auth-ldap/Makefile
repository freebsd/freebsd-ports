# Created by: Alexander Kriventsov <avk@vl.ru>
# $FreeBSD$

PORTNAME=	django-auth-ldap
PORTVERSION=	2.0.0
CATEGORIES=	www security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	LDAP integration for django.contrib.auth

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=1.11:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=3.1:net/py-ldap@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
PORTDOCS=	*
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-auth-ldap \
			${PYTHON_PKGNAMEPREFIX}dj22-django-auth-ldap

# The 2.1.0 release dropped support for Django 2.1
PORTSCOUT=      limit:^2\.0\.

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
 		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
