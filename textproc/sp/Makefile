# New ports collection makefile for:	sp
# Version required:	1.1.1
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $Id$
#

DISTNAME=	sp-1.1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	jfieber@FreeBSD.ORG

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
