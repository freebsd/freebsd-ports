# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	veusz
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.1
CATEGORIES=	science kde
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific plotting package

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang python:3.5+ pyqt:5 qt:5 shebangfix
USE_GITHUB=	yes
USE_PYQT=	core gui svg
USE_PYTHON=	distutils concurrent autoplist
USE_QT=		core gui xml widgets qmake_build
SHEBANG_FILES=	examples/embedexample.py

MAKE_ENV=       SIP_DIR=${LOCALBASE}/share/PyQt5/${PYTHON_VER}/sip

.include <bsd.port.mk>
