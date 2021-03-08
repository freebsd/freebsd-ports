# $FreeBSD$

PORTNAME=	QSpectrumAnalyzer
DISTVERSION=	2.1.0
PORTREVISION=	10
CATEGORIES=	misc hamradio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spectrum analyzer for multiple SDR platforms

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>=0.10.0:graphics/py-pyqtgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soapy_power>=1.5.0:misc/py-soapy_power@${PY_FLAVOR}

USES=		fortran python:3.4+ pyqt:5
USE_PYQT=	core gui widgets
USE_PYTHON=	distutils concurrent autoplist

PLIST_FILES=	bin/${PORTNAME:tl}.shadow

post-patch: # change from Qt.py that doesn't work to PyQt5
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -i '' -e ' \
		s|from Qt import |from PyQt5 import | ; \
		s|, __binding__|| ; \
		s|QtCore.Signal|QtCore.pyqtSignal| ; \
		s|QtCore.Slot|QtCore.pyqtSlot|'

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}.shadow
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc9/libgcc_s.so ${PREFIX}/bin/${PORTNAME:tl}.shadow \"$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}

.include <bsd.port.mk>
