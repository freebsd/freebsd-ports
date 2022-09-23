PORTNAME=	ebcdic
PORTVERSION=	1.1.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Additional EBCDIC codecs
WWW=	https://github.com/roskakori/CodecMapper

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	python:3.8+
USE_GITHUB=	yes
GH_ACCOUNT=	roskakori
GH_PROJECT=	CodecMapper
GH_TAGNAME=	v1.1.1
USE_PYTHON=	autoplist distutils unittest

WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>
