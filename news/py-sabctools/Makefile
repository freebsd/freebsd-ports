PORTNAME=	sabctools
PORTVERSION=	7.1.0
CATEGORIES=	news python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python yEnc package optimized for use within SABnzbd
WWW=		https://github.com/sabnzbd/sabctools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
