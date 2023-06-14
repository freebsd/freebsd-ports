PORTNAME=	ebcdic
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Additional EBCDIC codecs
WWW=		https://github.com/roskakori/CodecMapper

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	roskakori
GH_PROJECT=	CodecMapper
USE_PYTHON=	autoplist distutils unittest

NO_ARCH=	yes

WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>
