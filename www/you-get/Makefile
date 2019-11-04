# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	you-get
PORTVERSION=	0.4.1355
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dumb downloader that scrapes the web

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		python:3.4+
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

OPTIONS_DEFINE=	RTMPDUMP

RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump

.include <bsd.port.mk>
