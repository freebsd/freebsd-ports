# New ports collection makefile for:	coda-server
# Version required:			5.0.2
# Date created:				Fri Feb 19 19:03:33 EST 1999
# Whom:					root#
# $FreeBSD$
#

DISTNAME=	coda-5.0.2
PKGNAME=	coda-server-5.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

ALL_TARGET=	coda
INSTALL_TARGET=	server-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
