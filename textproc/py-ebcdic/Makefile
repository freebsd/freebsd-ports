PORTNAME=	ebcdic
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Additional EBCDIC codecs
WWW=		https://github.com/roskakori/CodecMapper

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	roskakori
GH_PROJECT=	CodecMapper
USE_PYTHON=	autoplist pep517 unittest

NO_ARCH=	yes

WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>
