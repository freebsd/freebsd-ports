# New ports collection makefile for:	SS
# Version required:			1.3.3
# Date created:				5 January 1997
# Whom:					pgiffuni@FPS.biblos.unal.edu.co
#
# $Id: porting.sgml,v 1.2.4.3 1997/11/16 01:59:13 pgs Exp $
#

DISTNAME=	ss_1.3.3
PKGNAME=	ss-1.3.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cs.ualberta.ca/pub/spreadsheet/

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

WRKSRC=		${WRKDIR}/ss_133
MAN1=		ss.1 pss.1

do-configure:
	@${CP} ${WRKSRC}/config.bsd  ${WRKSRC}/config.h

.include <bsd.port.mk>
