# New ports collection makefile for:	lbdb
# Version required:	0.18.5
# Date created:		2 February 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

DISTNAME=	lbdb_0.18.5
PKGNAME=	lbdb-0.18.5
CATEGORIES=	mail
MASTER_SITES=	http://www.rhein.de/~roland/debian/

MAINTAINER=	mwest@uct.ac.za

WRKSRC=		${WRKDIR}/lbdb-0.18.5
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--libdir=${PREFIX}/libexec
USE_GMAKE=	YES

MAN1=		nodelist2lbdb.1 lbdbq.1 lbdb-fetchaddr.1

.include <bsd.port.mk>
