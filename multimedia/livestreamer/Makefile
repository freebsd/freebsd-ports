# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	livestreamer
PORTVERSION=	1.12.2
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extract web streams and pipe them into video player of choice

LICENSE=	BSD2CLAUSE MIT APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}librtmp>=0:multimedia/py-librtmp

USES=		python
USE_PYTHON=	autoplist distutils
PATCH_STRIP=	-p1

.include <bsd.port.mk>
