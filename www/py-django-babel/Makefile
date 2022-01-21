# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	django-babel
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for using Babel in django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream no longer maintained, please use www/py-enmerkar instead
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.8:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
