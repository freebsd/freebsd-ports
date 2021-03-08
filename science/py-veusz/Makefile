# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	veusz
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific plotting package

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang python:3.5+ pyqt:5 qt:5 shebangfix
USE_GITHUB=	yes
USE_PYQT=	core gui printsupport svg widgets
USE_PYTHON=	distutils concurrent autoplist
USE_QT=		core gui xml widgets qmake_build
SHEBANG_FILES=	examples/embedexample.py

MAKE_ENV=	SIP_DIR=${LOCALBASE}/share/PyQt5/${PYTHON_VER}/sip

post-install:
	# strip
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/veusz/helpers/*.so
	# workaround for https://github.com/veusz/veusz/issues/475
	${REINPLACE_CMD} -i '' -e 's|PyQt5||' ${STAGEDIR}${PYTHON_SITELIBDIR}/*/requires.txt

.include <bsd.port.mk>
