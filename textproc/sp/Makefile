# New ports collection makefile for:	sp
# Version required:	1.1.1
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.1.1.1 1997/04/26 20:01:59 jfieber Exp $
#

DISTNAME=	sp-1.1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	jfieber@FreeBSD.ORG

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
