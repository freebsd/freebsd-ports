# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	you-get
PORTVERSION=	0.4.715
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dumb downloader that scrapes the web

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

OPTIONS_DEFINE=	RTMPDUMP

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:3

GH_ACCOUNT=	soimort
USE_GITHUB=	yes

RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump

.include <bsd.port.mk>
