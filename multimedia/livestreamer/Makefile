# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	livestreamer
PORTVERSION=	1.7.5
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extract web streams and pipe them into video player of choice

LICENSE=	BSD2CLAUSE MIT APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump \
		${PYTHON_PKGNAMEPREFIX}requests1>=0:${PORTSDIR}/www/py-requests1 \
		${PYTHON_PKGNAMEPREFIX}librtmp>=0:${PORTSDIR}/multimedia/py-librtmp

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
