# New ports collection makefile for:	youtube_dl
# Date created:		2006-08-12
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	youtube_dl
PORTVERSION=	2009.04.25
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/rg3/youtube-dl/raw/c42582904adf/
DISTNAME=	youtube-dl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	2.4+

PLIST_FILES=	bin/youtube-dl

OPTIONS=	FFMPEG "Use ffmpeg for avi output" off \
		FLV2MPEG4 "Use flv2mpeg4 for avi output" off

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG) || defined(WITH_FLV2MPEG4)
EXTRA_PATCHES+=	${PATCHDIR}/conv2avi.patch
.endif

.if defined(WITH_FFMPEG)
.if defined (WITH_FLV2MPEG4)
IGNORE=	cannot use WITH_FFMPEG and WITH_FLV2MPEG4 simultaneously
.endif
CONV2AVI_CMD=	${PREFIX}/bin/ffmpeg -y -i
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.elif defined (WITH_FLV2MPEG4)
CONV2AVI_CMD=	${PREFIX}/bin/flv2mpeg4
RUN_DEPENDS+=	flv2mpeg4:${PORTSDIR}/multimedia/flv2mpeg4
.endif

post-extract:
	@${CP} ${DISTDIR}/youtube-dl ${WRKSRC}/youtube-dl

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' ${WRKSRC}/youtube-dl
.if defined(WITH_FFMPEG) || defined(WITH_FLV2MPEG4)
	@${REINPLACE_CMD} -e 's|%%CONV2AVI_CMD%%|${CONV2AVI_CMD}|' ${WRKSRC}/youtube-dl
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl

.include <bsd.port.post.mk>
