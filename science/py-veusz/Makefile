# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	veusz
PORTVERSION=	1.19.1
PORTREVISION=	5
CATEGORIES=	science kde
MASTER_SITES=	http://download.gna.org/veusz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	devel@stasyan.com
COMMENT=	Scientific plotting package

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYNUMPY}

USES=		python pyqt:4 qt:4 shebangfix
USE_PYQT=	gui svg
USE_PYTHON=	distutils concurrent autoplist
USE_QT=		corelib gui xml
SHEBANG_FILES=	examples/embedexample.py

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/veusz/helpers/*.so

.include <bsd.port.mk>
