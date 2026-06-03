PORTNAME=	misaki
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	misc python # machine learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grapheme-to-phoneme engine with modular architecture
WWW=		https://github.com/hexgrad/misaki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}addict>0:devel/py-addict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

#OPTIONS_DEFINE=		EN JA KO ZH
OPTIONS_DEFINE=		EN JA KO
OPTIONS_DEFAULT=	EN
EN_DESC=		English language support
JA_DESC=		Japanese language support
KO_DESC=		Korean language support
#ZH_DESC=		Chinese language support

EN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}num2words>0:devel/py-num2words@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spacy>0:textproc/py-spacy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}en-core-web-sm>0:textproc/py-en-core-web-sm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonemizer-fork>0:textproc/py-phonemizer-fork@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}espeakng_loader>0:audio/py-espeakng-loader@${PY_FLAVOR}
JA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fugashi>0:japanese/py-fugashi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaconv>0:japanese/py-jaconv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mojimoji>0:japanese/py-mojimoji@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidic>0:japanese/py-unidic@${PY_FLAVOR}
JA_BROKEN=	openjtalk and pyopenjtalk need to be ported
KO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jamo>0:korean/py-jamo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk@${PY_FLAVOR}
KO_BROKEN=	see https://github.com/hexgrad/misaki/issues/96
# chinese/py-jieba requires paddlepaddle which is extremely convoluted and can't yet be ported: disable Chinese for now
#ZH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jieba>0:chinese/py-jieba@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}ordered-set>0:devel/py-ordered-set@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pypinyin>0:chinese/py-pypinyin@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pypinyin-dict>0:chinese/py-pypinyin-dict@${PY_FLAVOR}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test-EN-on: # run the example since there are no tests defined
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/examples/usage.py

.include <bsd.port.mk>
