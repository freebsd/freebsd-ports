# New ports collection makefile for:	bookmarkbridge
# Date Created:				January 2004
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	bookmarkbridge
PORTVERSION=	0.72
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bookmarkbridge

MAINTAINER=	molter@gufi.org
COMMENT=	Synchronize bookmarks between multiple browsers

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_QT_VER=	3
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mt --program-prefix="" \
		--with-libxml2-include="${LOCALBASE}/include/libxml2"

.include <bsd.port.mk>
