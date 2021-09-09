# Created by: Alexander Kriventsov <avk@vl.ru>

PORTNAME=	django-auth-ldap
PORTVERSION=	3.0.0
CATEGORIES=	www security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	LDAP integration for django.contrib.auth

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 3.1 ends December 2021, upgrade to the Django 3.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2021-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.2:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=3.1:net/py-ldap@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTDOCS=	*
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-auth-ldap \
			${PYTHON_PKGNAMEPREFIX}dj32-django-auth-ldap

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

.include <bsd.port.pre.mk>

# Set a locale to avoid build/configure errors.  The UTF-8 mode is enabled by
# default when the locale is C since Python 3.7.
.if ${PYTHON_REL} < 30700
USE_LOCALE=	en_US.UTF-8
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
 		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.post.mk>
