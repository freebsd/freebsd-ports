# New ports collection makefile for:	sp
# Version required:	1.2.1
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.5 1997/09/07 00:20:02 jfieber Exp $
#

DISTNAME=	sp-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	jfieber@FreeBSD.ORG

# The shared libsp only works on post 2.1.x systems.
# shared C++ libraries appear to be broken on post 2.2.1 system too...
#.if exists(/usr/lib/libstdc++.a)
#PLIST=		${PKGDIR}/PLIST-shared
#post-install:
#	${LDCONFIG} -m ${PREFIX}/lib
#.endif

.include <bsd.port.mk>
