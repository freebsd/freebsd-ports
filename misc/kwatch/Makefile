# New ports collection makefile for:   kwatch
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <zerium@webindex.no>
#
# $FreeBSD$
#

PORTNAME=	kwatch
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://www.m-j-s.net/pub/kde/ \
		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/admin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE/Qt log file viewer

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-O2 ,,g ; \
		 s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KFILE)$$,$$(LIB_KFILE) $$(LIBPTHREAD),g' \
			${WRKSRC}/kwatch/Makefile.in

.include <bsd.port.mk>
