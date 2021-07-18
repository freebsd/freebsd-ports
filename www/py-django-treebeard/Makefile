PORTNAME=	django-treebeard
DISTVERSION=	4.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Efficient tree implementations for Django

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

.include <bsd.port.pre.mk>
# Set a locale to avoid build/configure errors.  The UTF-8 mode is enabled by
# default when the locale is C since Python 3.7.
.if ${PYTHON_REL} < 30700
USE_LOCALE=	en_US.UTF-8
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
