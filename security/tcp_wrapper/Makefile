# New ports collection makefile for:	tcp_wrapper
# Version required:     7.6
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.15 1997/06/20 17:49:51 max Exp $
#

DISTNAME=       tcp_wrappers_7.6
PKGNAME=        tcp_wrappers-7.6
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=	freebsd
MAN3=		hosts_access.3
MAN5=		hosts_access.5 hosts_options.5
MAN8=		tcpd.8 tcpdchk.8 tcpdmatch.8

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
