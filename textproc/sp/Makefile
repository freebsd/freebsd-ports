# New ports collection makefile for:	sp
# Version required:	1.1.1
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.2 1997/04/27 01:06:45 asami Exp $
#

DISTNAME=	sp-1.1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	jfieber@FreeBSD.ORG

# The shared libsp only works on post 2.1.x systems.
.if exists(/usr/lib/libstdc++.a)
PLIST=		${PKGDIR}/PLIST-shared
post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.endif

.include <bsd.port.mk>
