# New ports collection makefile for:	coda
# Version required:			4.6.5
# Date created:				19 June 1998
# Whom:					hmpierce <hmpierce@cs.cmu.edu>
#
# $Id: Makefile,v 1.2 1998/10/09 20:47:11 rvb Exp $
#

DISTNAME=	coda-4.6.6
PKGNAME=	coda-server-4.6.6.1
CATEGORIES=	net
#MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

ALL_TARGET=	coda
INSTALL_TARGET=	server-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
