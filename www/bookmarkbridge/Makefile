# New ports collection makefile for:	bookmarkbridge
# Date Created:				January 2004
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	bookmarkbridge
PORTVERSION=	0.70
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	/bookmarkbridge

MAINTAINER=	molter@gufi.org
COMMENT=	Synchronize bookmarks between multiple browsers

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_QT_VER=	3
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS=-lcipher
CONFIGURE_ARGS=	--enable-mt --program-prefix=""

.include <bsd.port.mk>
