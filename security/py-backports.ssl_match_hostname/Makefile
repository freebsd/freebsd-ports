# $FreeBSD$

PORTNAME=	backports.ssl_match_hostname
PORTVERSION=	3.5.0.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Backport of the ssl_match_hostname function from Python 3.5

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>0:devel/py-backports@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

POST_PLIST=	trim-backports-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__pycache__

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}
	@${REINPLACE_CMD} '/backports\/__pycache__*/d' ${TMPPLIST}

.include <bsd.port.mk>
