# New ports collection makefile for:	radius
# Version required:	merit radius 2.4.21
# Date created:		4. July 1996
# Whom:			torstenb@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	radius.2.4.21
PKGNAME=	radius-2.4.21
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/pub/radius/release/

# Restrictive copyright in src/rlmadmin.c
RESTRICTED= "use for non-profit, non-commercial purposes on a shareware basis"

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install-all

pre-install:
	mkdir -p ${PREFIX}/lib/radius/db ${PREFIX}/lib/radius/acct

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man5/authfile.5 ${PREFIX}/man/man5/clients.5 \
		${PREFIX}/man/man5/dictionary.5 ${PREFIX}/man/man5/users.5 \
		${PREFIX}/man/man8/builddbm.8 ${PREFIX}/man/man8/radcheck.8 \
		${PREFIX}/man/man8/radiusd.8 ${PREFIX}/man/man8/radpwtst.8 \
		${PREFIX}/man/man8/rlmadmin.8
.endif

.include <bsd.port.mk>
