# New ports collection makefile for: gd
# Version required:     1.3
# Date created:         17 Aug 1998
# Whom:                 gsm@infosite.ru
#
# $FreeBSD$
#

DISTNAME=       gd1.3
PKGNAME=        ru-gd-1.3
CATEGORIES=	russian graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=     gsm@infosite.ru

RESTRICTED=	unavailable from master site due to legal problems

FETCH_BEFORE_ARGS=	-b

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
