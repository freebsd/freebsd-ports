# New ports collection makefile for:	youtube_dl
# Date created:		2006-08-12
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	youtube_dl
PORTVERSION=	2007.03.27
CATEGORIES=	www
MASTER_SITES=	http://www.arrakis.es/~rggi3/youtube-dl/
DISTNAME=	youtube-dl-${PORTVERSION}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A program for downloading videos from YouTube.com

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	2.4+

PLIST_FILES=	bin/youtube-dl

OPTIONS=	FFMPEG "With optional avi output format" off

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG)
RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
EXTRA_PATCHES+=	${PATCHDIR}/ffmpeg.patch
.endif

post-extract:
	@${CP} ${DISTDIR}/youtube-dl-${PORTVERSION} ${WRKSRC}/youtube-dl

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' ${WRKSRC}/youtube-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${TARGETDIR}/bin/youtube-dl

.include <bsd.port.post.mk>
