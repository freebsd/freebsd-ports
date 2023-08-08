PORTNAME=	patiencediff
PORTVERSION=	0.2.12
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Implementation of the "Patience Diff" algorithm
WWW=		https://pypi.org/project/patiencediff/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist distutils pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/patiencediff/_patiencediff_c*.so

.include <bsd.port.mk>
