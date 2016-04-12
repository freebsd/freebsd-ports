# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyquery
PORTVERSION=	1.2.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Jquery-like library for python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:www/py-webob

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

USES=		python zip
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_VARS=	PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -or ! -name objects.inv")

.include <bsd.port.mk>
