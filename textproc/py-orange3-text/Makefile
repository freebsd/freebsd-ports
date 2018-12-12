# $FreeBSD$

PORTNAME=	orange3-text
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text Mining add-on for Orange3

LICENSE=	AGPLv3

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docx2txt>=0.6:textproc/py-docx2txt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gensim>=0.12.3:textproc/py-gensim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.0.5:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}odfpy>=1.3.5:devel/py-odfpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer3k>0:textproc/py-pdfminer3k@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simhash>0:math/py-simhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tweepy>0:net/py-tweepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufal.udpipe>0:textproc/py-ufal.udpipe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate_email>0:mail/py-validate_email@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wikipedia>0:www/py-wikipedia@${PY_FLAVOR}
py34_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}typing>0:devel/py-typing@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
