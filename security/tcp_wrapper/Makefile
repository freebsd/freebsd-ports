# New ports collection makefile for:	tcp_wrapper
# Version required:     7.2
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.12 1996/01/25 05:54:17 ache Exp $
#

DISTNAME=       tcp_wrappers_7.4
PKGNAME=        tcp_wrappers-7.4
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=	freebsd

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man3/hosts_access.3 \
	${PREFIX}/man/man5/hosts_access.5 ${PREFIX}/man/man5/hosts_options.5 \
	${PREFIX}/man/man8/tcpd.8 ${PREFIX}/man/man8/tcpdchk.8 \
	${PREFIX}/man/man8/tcpdmatch.8
.endif

.include <bsd.port.mk>
