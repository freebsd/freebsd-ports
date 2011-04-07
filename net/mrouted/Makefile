# New ports collection makefile for:	mrouted
# Date created:		28 September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrouted
PORTVERSION=	3.9.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.vmlinux.org/pub/People/jocke/mrouted/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Multicast routing daemon providing DVMRP for IPv4

USE_RC_SUBR=	mrouted
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	sysconfdir=${PREFIX}/etc \
		mandir=${MAN8PREFIX}/man/man8

MAN8=		map-mbone.8 mrouted.8 mrinfo.8 mtrace.8
PORTDOCS=	*

PLIST_FILES=	sbin/map-mbone sbin/mrouted sbin/mrinfo sbin/mtrace \
		etc/mrouted.conf

.ifdef	NOPORTDOCS
MAKE_ARGS+=	datadir=${WRKDIR}/doc
.endif

.include <bsd.port.mk>
