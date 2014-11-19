# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	patsy
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Python package for statistical models and design matrices

LICENSE=	BSD

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	API-reference.rst \
		R-comparison.rst \
		builtins-reference.rst \
		categorical-coding.rst \
		changes.rst \
		expert-model-specification.rst \
		formulas.rst \
		index.rst \
		library-developers.rst \
		overview.rst \
		py2-versus-py3.rst \
		quickstart.rst \
		stateful-transforms.rst \

PORTEXAMPLES=	add_predictors.py \
		example_lm.py \
		example_treatment.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/_examples/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
