# $FreeBSD$

PORTNAME=	orange3-text
DISTVERSION=	0.3.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text Mining add-on for Orange3

LICENSE=	AGPLv3

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docx2txt>=0.6:textproc/py-docx2txt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gensim>=0.12.3:textproc/py-gensim@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.0.5:textproc/py-nltk@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}odfpy>=1.3.5:devel/py-odfpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer3k>0:textproc/py-pdfminer3k@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simhash>0:math/py-simhash@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tweepy>0:net/py-tweepy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate_email>0:mail/py-validate_email@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wikipedia>0:www/py-wikipedia@${FLAVOR}
py34_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}typing>0:devel/py-typing@${FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
