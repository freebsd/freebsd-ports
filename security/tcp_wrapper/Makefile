# New ports collection makefile for:	tcp_wrapper
# Version required:     7.2
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.6 1995/04/15 05:41:56 asami Exp $
#

DISTNAME=       tcp_wrappers_7.2
PKGNAME=        tcp_wrappers-7.2
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/

ALL_TARGET=	freebsd

post-install:
	gzip -9nf ${PREFIX}/man/man3/hosts_access.3 \
	${PREFIX}/man/man5/hosts_access.5 ${PREFIX}/man/man5/hosts_options.5 \
	${PREFIX}/man/man8/tcpd.8 ${PREFIX}/man/man8/tcpdchk.8 \
	${PREFIX}/man/man8/tcpdmatch.8


.include <bsd.port.mk>
