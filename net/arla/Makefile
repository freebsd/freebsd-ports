# New ports collection makefile for:	arla
# Version required:		2.7.1ac-0.84
# Date created:			09 Sep 1998
# Whom:				Peter Hawkins <thepish@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1997/07/13 18:49:26 max Exp $
#

DISTNAME=	arla-0.9
PKGNAME=	arla-0.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/arla/
BUILD_DEPENDS=	/usr/lib/libkafs.a:/usr/src/kerberosIV/lib/libkafs

MAINTAINER=	thepish@freebsd.org

CONFIGURE_ARGS=	--prefix=$(PREFIX)
HAS_CONFIGURE=	YES

.include "bsd.port.mk"
