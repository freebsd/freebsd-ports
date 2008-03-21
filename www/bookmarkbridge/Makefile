# New ports collection makefile for:	bookmarkbridge
# Date Created:				January 2004
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	bookmarkbridge
PORTVERSION=	0.72
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synchronize bookmarks between multiple browsers

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_PERL5_BUILD=yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mt --program-prefix="" \
		--with-libxml2-include="${LOCALBASE}/include/libxml2"

.include <bsd.port.mk>
