PORTNAME=	ohmu
PORTVERSION=	1.1.0
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to view space usage in your terminal
WWW=		https://gitlab.com/paul-nechifor/ohmu

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	paul-nechifor

USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix
NO_ARCH=	yes

pre-configure:
	${REINPLACE_CMD} -e 's/future==0.15.2/future>=0.15.2/' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
