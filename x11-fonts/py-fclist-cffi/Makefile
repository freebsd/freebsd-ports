PORTNAME=	fclist-cffi
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python cffi bridge to fontconfig's FcFontList/FcFontMatch
WWW=		https://github.com/MonsieurV/python-fclist

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.17.1:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
