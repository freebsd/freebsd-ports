# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pafy
PORTVERSION=	0.5.0
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API for YouTube

LICENSE=	GPLv3

# At the moment the internal backend does not work
BUILD_DEPENDS=	youtube_dl>=2016.02.22:www/youtube_dl
RUN_DEPENDS=	youtube_dl>=2016.02.22:www/youtube_dl

USES=	python
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@(cd ${WRKSRC}/${PORTNAME} && \
	${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE},1" pafy.py backend_youtube_dl.py)

.include <bsd.port.mk>
