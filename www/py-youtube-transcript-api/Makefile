PORTNAME=	youtube-transcript-api
DISTVERSION=	0.6.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module for YouTube Transcript/Subtitle API
WWW=		https://github.com/jdepoix/youtube-transcript-api

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
