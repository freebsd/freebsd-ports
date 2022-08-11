PORTNAME=	pafy
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API for YouTube

LICENSE=	GPLv3

# At the moment the internal backend does not work
BUILD_DEPENDS=	yt-dlp:www/yt-dlp
RUN_DEPENDS=	yt-dlp:www/yt-dlp

USES=	python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@(cd ${WRKSRC}/${PORTNAME} && \
	${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE},1" pafy.py backend_youtube_dl.py)

.include <bsd.port.mk>
