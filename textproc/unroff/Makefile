# New ports collection makefile for:	unroff
# Version required:	1.0
# Date created:		18 Feb 1996
# Whom:			Thomas Gellekum <thomas@ghpc8.ihf.rwth-aachen.de>
#
# $Id: Makefile,v 1.1.1.1 1996/04/10 06:38:58 tg Exp $
#

DISTNAME=	unroff-1.0
CATEGORIES+=	print
MASTER_SITES=	http://www-rn.informatik.uni-bremen.de/software/unroff/dist/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

RUN_DEPENDS=	elk:${PORTSDIR}/lang/elk
BUILD_DEPENDS=	elk:${PORTSDIR}/lang/elk

PATCH_STRIP=	-p1

.include <bsd.port.mk>
