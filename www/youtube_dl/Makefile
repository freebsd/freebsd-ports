# New ports collection makefile for:	youtube_dl
# Date created:		2006-08-12
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	youtube_dl
PORTVERSION=	2011.10.19
CATEGORIES=	www
MASTER_SITES=	https://raw.github.com/rg3/youtube-dl/${PORTVERSION}/
DISTNAME=	youtube-dl
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON_RUN=	2.5-2.7

PLIST_FILES=	bin/youtube-dl

OPTIONS=	RTMPDUMP	"Use RTMPDUMP to download rtmp video streams"	on

.include <bsd.port.options.mk>

.if defined(WITH_RTMPDUMP)
RUN_DEPENDS+=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/youtube-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl

.include <bsd.port.mk>
