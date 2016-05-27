# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	bottleneck
PORTVERSION=	1.0.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Bottleneck-${PORTVERSION}

MAINTAINER=	xmj@FreeBSD.org
COMMENT=	Collection of fast NumPy array functions written in Cython

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		cython:lang/cython
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

regression-test: build
	@cd ${WRKSRC} && nosetests

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/RELEASE.rst ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/source/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
