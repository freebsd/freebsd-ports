# New ports collection makefile for:	radius
# Date created:		4. July 1996
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	radius-basic
PORTVERSION=	3.6B2
CATEGORIES=	net
DISTNAME=	radius.${PORTVERSION}.basic

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

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Goto radius\' website: \
	\"http://www.interlinknetworks.com/downloads/\#freeware\" \
	to get more info on downloading the tarball, then place \
	${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} and run make again"
.endif

.include <bsd.port.post.mk>
