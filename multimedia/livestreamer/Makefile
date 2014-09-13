# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	livestreamer
PORTVERSION=	1.10.2
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extract web streams and pipe them into video player of choice

LICENSE=	BSD2CLAUSE MIT APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump \
		${PYTHON_PKGNAMEPREFIX}requests1>=0:${PORTSDIR}/www/py-requests1 \
		${PYTHON_PKGNAMEPREFIX}futures>=0:${PORTSDIR}/devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}librtmp>=0:${PORTSDIR}/multimedia/py-librtmp

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
