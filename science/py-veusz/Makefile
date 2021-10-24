# Created by: Stas Timokhin <devel@stasyan.com>

PORTNAME=	veusz
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.4
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
USE_PYQT=	pyqt5 sip
USE_PYTHON=	distutils concurrent autoplist
USE_QT=		core gui xml widgets qmake_build
SHEBANG_FILES=	examples/embedexample.py

post-install:
	# strip
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/veusz/helpers/*.so

.include <bsd.port.mk>
