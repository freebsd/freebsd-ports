# New ports collection makefile for:	tcp_wrapper
# Version required:     7.2
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/01/10 00:07:21 torstenb Exp $
#

DISTNAME=       tcp_wrappers_7.2
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/
ALL_TARGET=	freebsd

pre-install:
	@mkdir -p ${PREFIX}/sbin
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/libexec
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/etc
	@mkdir -p ${PREFIX}/man/man3
	@mkdir -p ${PREFIX}/man/man5
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
