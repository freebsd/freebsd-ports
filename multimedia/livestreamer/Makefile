# Created by: Juergen Lock <nox@FreeBSD.org>

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

BROKEN=		Doesn't work, multiple reports upstream
DEPRECATED=	Abandoned upstream, please consider using www/yt-dlp or multimedia/streamlink
EXPIRATION_DATE=2022-06-30

RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}librtmp>=0:multimedia/py-librtmp@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
PATCH_STRIP=	-p1

.include <bsd.port.mk>
