# New ports collection makefile for:	coda-client
# Version required:			5.0.1
# Date created:				Fri Jan 22 15:19:11 EST 1999
# Whom:					jaharkes#
# $FreeBSD$
#

DISTNAME=	coda-5.0.1
PKGNAME=	coda-client-5.0.1
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
