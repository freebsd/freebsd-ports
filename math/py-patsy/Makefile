# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	patsy
PORTVERSION=	0.4.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johannes@perceivon.net
COMMENT=	Python package for statistical models and design matrices

LICENSE=	BSD3CLAUSE PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/_examples/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
