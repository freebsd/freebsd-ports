# New ports collection makefile for:	coda-client
# Version required:			5.3.2
# Date created:				Mon Oct  18 12:01:27 EDT 1999
# Whom:					???
# $FreeBSD$
#

DISTNAME=	coda-5.3.2
PKGNAME=	coda-client-5.3.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
