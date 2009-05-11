# New ports collection makefile for:	youtube_dl
# Date created:		2006-08-12
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	youtube_dl
PORTVERSION=	2009.04.25
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/rg3/youtube-dl/raw/2009.04.25/
DISTNAME=	youtube-dl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	2.5+

PLIST_FILES=	bin/youtube-dl

post-extract:
	@${CP} ${DISTDIR}/youtube-dl ${WRKSRC}/youtube-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl

.include <bsd.port.mk>
