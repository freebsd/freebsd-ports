# New ports collection makefile for:	radius
# Date created:		4. July 1996
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	radius-basic
PORTVERSION=	3.6B
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/
DISTNAME=	radius.3.6B.basic

MAINTAINER=	ports@FreeBSD.org

# restrictive copyright in several files, e.g., "src/sendserver.c"
RESTRICTED=	redistribution in binary only
NO_CDROM=	not allowed to charge fee for redistribution

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install-all
MAKE-FLAGS+=	-DPREFIX=${PREFIX}
MAN5=		authfile.5 clients.5 dictionary.5 engine.config.5 \
		radius.fsm.5 users.5 vendors.5
MAN8=		builddbm.8 dnscheck.8 radcheck.8 radiusd.8 radpwtst.8

pre-install:
	@${MKDIR} ${PREFIX}/lib/radius/db ${PREFIX}/lib/radius/acct

.include <bsd.port.mk>
