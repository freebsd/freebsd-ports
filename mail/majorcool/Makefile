# New ports collection makefile for:	majorcool
# Version required:		unknown
# Date created:			Wed Aug 13 18:34:14 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	majorcool
CATEGORIES=	mail
MASTER_SITES=	http://ncrinfo.ncr.com/pub/contrib/unix/MajorCool/
WRKSRC=		${WRKDIR}

MAINTAINER=	andreas@FreeBSD.ORG

NO_BUILD=	yes
NO_PACKAGE=	"Too many questions"

do-install:
		( cd ${WRKSRC}; ${SH} Configure )

.include <bsd.port.mk>
