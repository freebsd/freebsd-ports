# New ports collection makefile for:	coda
# Date created:				19 June 1998
# Whom:					hmpierce <hmpierce@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	coda-client
PORTVERSION=	4.6.6.1
CATEGORIES=	net
#MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTNAME=	coda-4.6.6
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

BROKEN=		"Does not build"

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_LATEST_LINK=	yes

.include <bsd.port.mk>
