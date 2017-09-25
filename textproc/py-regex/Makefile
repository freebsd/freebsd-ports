# $FreeBSD$

PORTNAME=	regex
PORTVERSION=	2017.09.23
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	Alternative regular expression module, to replace re

LICENSE=	PSFL

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_regex.so

.include <bsd.port.mk>
