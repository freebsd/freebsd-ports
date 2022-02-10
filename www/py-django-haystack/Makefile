# Created by: Kristaps Kulis <kristaps.kulis@gmail.com>

PORTNAME=	django-haystack
PORTVERSION=	3.1.1
CATEGORIES=	www databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pluggable search for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS ELASTIC
OPTIONS_DEFAULT=	ELASTIC

ELASTIC_DESC=	Enable Elasticsearch support

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"
ELASTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch5>=5<6:textproc/py-elasticsearch5@${PY_FLAVOR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
