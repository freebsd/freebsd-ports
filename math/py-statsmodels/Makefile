# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	statsmodels
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.12:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.2.1:math/py-patsy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.11:science/py-scipy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent cython distutils

PORTDOCS=	README.rst README_l1.txt
PORTEXAMPLES=	*

SHEBANG_GLOB=	*.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/README_l1.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
