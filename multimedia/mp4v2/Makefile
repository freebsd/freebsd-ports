# New ports collection makefile for:	mpeg4ip-libmp4v2
# Date created:		28 Sep 2004
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mp4v2
PORTVERSION=	1.9.1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library and tools to read, create, and modify mp4 files

CONFLICTS=	mpeg4ip-libmp4v2-[0-9.]*
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	"FOUND_HELP2MAN=no"

MAN1=	mp4art.1 \
	mp4file.1 \
	mp4subtitle.1 \
	mp4track.1

.include <bsd.port.mk>
