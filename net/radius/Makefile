# New ports collection makefile for:	radius
# Version required:	merit radius 2.4.23
# Date created:		4. July 1996
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.7 1997/08/26 12:17:56 markm Exp $
#

DISTNAME=	radius.2.4.23
PKGNAME=	radius-2.4.23
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/
DISTFILES=	radius.23c.basic.tar.gz

MAINTAINER=	torstenb@FreeBSD.ORG

# restrictive copyright in several files, e.g., "src/sendserver.c"
RESTRICTED=	redistribution in binary only
NO_CDROM=	not allowed to charge fee for redistribution

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install-all
MAKE-FLAGS+=	-DPREFIX=${PREFIX}
MAN5=		dictionary.5 users.5 radius.fsm.5 authfile.5 clients.5
MAN8=		builddbm.8 radcheck.8 radiusd.8 radpwtst.8

pre-install:
	@${MKDIR} ${PREFIX}/lib/radius/db ${PREFIX}/lib/radius/acct

.include <bsd.port.mk>
