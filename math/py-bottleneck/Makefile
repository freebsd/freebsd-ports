# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	bottleneck
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Bottleneck-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of fast NumPy array functions written in Cython

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/bottleneck/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

DOCS=		README.rst RELEASE.rst \
		doc/source/conf.py doc/source/index.rst doc/source/intro.rst doc/source/reference.rst
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bottleneck/*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
