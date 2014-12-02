# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-oauth-hook
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This is an OAuth hook for py-requests

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>0:${PORTSDIR}/www/py-requests1 \
		${PYTHON_PKGNAMEPREFIX}oauth2>0:${PORTSDIR}/net/py-oauth2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
