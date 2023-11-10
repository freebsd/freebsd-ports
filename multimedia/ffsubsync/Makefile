PORTNAME=	ffsubsync
DISTVERSION=	0.4.25
CATEGORIES=	multimedia python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synchronize your subtitles using machine learning
WWW=		https://github.com/smacke/ffsubsync

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}auditok>=0.1.5:audio/py-auditok@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}faust-cchardet>0:textproc/py-faust-cchardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ffmpeg-python>0:multimedia/py-ffmpeg-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pysubs2>=1.2.0:multimedia/py-pysubs2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srt>=3.0.0:multimedia/py-srt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webrtcvad>0:audio/py-webrtcvad@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	smacke # tympanix account has another version of the same project requiring tensorflow
USE_PYTHON=	pep517 noflavors autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
