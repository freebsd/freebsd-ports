# Created by: John Hixson <john@ixsystems.com>
# $FreeBSD$

PORTNAME=	django-simple-captcha
PORTVERSION=	0.5.12
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Simple, yet powerful, Django captcha application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.7.0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-ranged-response>=0.2.0:www/py-django-ranged-response@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.2.0:devel/py-six@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS MIGRATIONS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"
MIGRATIONS_DESC=	Schema and data migration support (via south)
MIGRATIONS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>0:databases/py-south@${PY_FLAVOR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
