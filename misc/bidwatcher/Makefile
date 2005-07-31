# ex:ts=8
# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	bidwatcher
PORTVERSION=	1.3.17
PORTREVISION?=	0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

#PATCH_SITES=	http://sourceforge.net/tracker/download.php?group_id=2973&atid=302973&file_id=112451&aid=1085302
#PATCHFILES=	bidwatcher-1.3.16-SSL_with_libcurl.02.patch
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	mph@FreeBSD.org
COMMENT=	Bid monitor for eBay

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

PLIST_FILES=	bin/bidwatcher
USE_GCC=	3.2+
USE_GNOME=	gtk12
GNU_CONFIGURE=	YES
CFLAGS+=	-UHAVE_GMTIME -DHAVE_TM_ZONE
MAN1=		bidwatcher.1

.include <bsd.port.mk>
