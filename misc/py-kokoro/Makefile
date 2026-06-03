PORTNAME=	kokoro
DISTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text-to-speech inference library for Kokoro-82M model
WWW=		https://github.com/hexgrad/kokoro \
		https://huggingface.co/hexgrad/Kokoro-82M

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}misaki>=0.9.4:misc/py-misaki@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}num2words>0:devel/py-num2words@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spacy>0:textproc/py-spacy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=0:misc/py-transformers@${PY_FLAVOR}
# extra run dependencies for kokoro-text-to-audio and kokoro-text-to-wav
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>0:audio/py-SoundFile@${PY_FLAVOR} \
		mpv:multimedia/mpv

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

PLIST_FILES=	bin/kokoro-text-to-audio \
		bin/kokoro-text-to-wav

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/kokoro-text-to-audio.py ${STAGEDIR}${PREFIX}/bin/kokoro-text-to-audio
	${INSTALL_SCRIPT} ${FILESDIR}/kokoro-text-to-wav.py ${STAGEDIR}${PREFIX}/bin/kokoro-text-to-wav
	@${REINPLACE_CMD} -i '' 's|%%PYTHON%%|${PYTHON_CMD}|' \
		${STAGEDIR}${PREFIX}/bin/kokoro-text-to-audio \
		${STAGEDIR}${PREFIX}/bin/kokoro-text-to-wav

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py && \
		mpv 0.wav

.include <bsd.port.mk>
