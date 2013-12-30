# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	livestreamer
PORTVERSION=	1.7.1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extract web streams and pipe them into video player of choice

LICENSE=	BSD MIT APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump \
		${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}librtmp>=0:${PORTSDIR}/multimedia/py-librtmp

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
