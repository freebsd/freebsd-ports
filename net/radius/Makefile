# New ports collection makefile for:	radius
# Version required:	merit radius 2.4.21
# Date created:		4. July 1996
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1996/07/12 10:53:34 asami Exp $
#

DISTNAME=	radius.2.4.21
PKGNAME=	radius-2.4.21
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/

# Restrictive copyright in src/rlmadmin.c
RESTRICTED= "use for non-profit, non-commercial purposes on a shareware basis"

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install-all
MAN5=		authfile.5 clients.5 dictionary.5 users.5
MAN8=		builddbm.8 radcheck.8 radiusd.8 radpwtst.8 rlmadmin.8

pre-install:
	${MKDIR} ${PREFIX}/lib/radius/db ${PREFIX}/lib/radius/acct

.include <bsd.port.mk>
