PORTNAME=	you-get
PORTVERSION=	0.4.1718
CATEGORIES=	www
MASTER_SITES=	PYPI \
		https://github.com/soimort/you-get/releases/download/v${PORTVERSION}/
DISTNAME=	you_get-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dumb downloader that scrapes the web
WWW=		https://you-get.org/ \
		https://github.com/soimort/you-get

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}dukpy>=0:devel/py-dukpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 noflavors

NO_ARCH=	yes

OPTIONS_DEFINE=	SOCKS
SOCKS_DESC=	SOCKS support

SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR}

.include <bsd.port.mk>
