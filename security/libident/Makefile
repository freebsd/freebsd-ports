# New ports collection makefile for:	libident
# Version required:	0.18
# Date created:		9 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1995/10/12 07:29:17 asami Exp $
#

DISTNAME=	libident-0.18
CATEGORIES=	devel net security
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/libs/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=	freebsd

post-install:
	gzip -9nf ${PREFIX}/man/man3/ident.3

.include <bsd.port.mk>
