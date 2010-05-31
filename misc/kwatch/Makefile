# New ports collection makefile for:   kwatch
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <zerium@webindex.no>
#
# $FreeBSD$
#

PORTNAME=	kwatch
PORTVERSION=	2.3.3
PORTREVISION=	8
CATEGORIES=	misc kde
MASTER_SITES=	http://www.m-j-s.net/pub/kde/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE/Qt log file viewer

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

DOCSDIR=	${PREFIX}/share/doc/HTML

post-patch:
	@${REINPLACE_CMD} -e 's,-O2 ,,g ; \
		 s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KFILE)$$,$$(LIB_KFILE) $$(LIBPTHREAD),g' \
			${WRKSRC}/kwatch/Makefile.in

.include <bsd.port.mk>
