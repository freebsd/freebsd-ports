# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bitmessage
DISTVERSION=	0.6.3.2
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure P2P communications client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:devel/py-qt4-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=${PYQT4_VERSION}:net/py-qt4-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:x11-toolkits/py-qt4-gui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject>0:devel/py-gobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notify2>0:devel/py-notify2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopencl>0:devel/py-pyopencl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR}

USES=		gmake python:2.7 pyqt:4 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Bitmessage
GH_PROJECT=	PyBitmessage
USE_PYQT=	core_run gui_run network_run
USE_PYTHON=	distutils autoplist noflavors
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|^#!.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/build/compiletest.py ${WRKSRC}/src/bitmessagecli.py ${WRKSRC}/src/bitmessagemain.py \
		${WRKSRC}/src/depends.py \
		${WRKSRC}/src/bitmessageqt/migrationwizard.py ${WRKSRC}/src/bitmessageqt/newaddresswizard.py \
		${WRKSRC}/src/bitmessageqt/settingsmixin.py ${WRKSRC}/src/helper_msgcoding.py ${WRKSRC}/src/openclpow.py

do-build:
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC} -f ${WRKSRC} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC} -f ${WRKSRC})

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pybitmessage/bitmsghash/bitmsghash.so

.include <bsd.port.mk>
