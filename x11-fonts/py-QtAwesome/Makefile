PORTNAME=	QtAwesome
DISTVERSION=	1.4.0
CATEGORIES=	x11-fonts graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME:tl}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Iconic fonts in PyQt and PySide applications
WWW=		https://github.com/spyder-ide/qtawesome

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}QtPy>0:devel/py-QtPy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
