# New ports collection makefile for:	majorcool
# Version required:		1.2.0
# Date created:			Wed Aug 13 18:34:14 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.4 1997/11/30 13:16:19 andreas Exp $
#

DISTNAME=	majorcool-1.20
PKGNAME=	majorcool-1.2.0
CATEGORIES=	mail
MASTER_SITES=	http://ncrinfo.ncr.com/pub/contrib/unix/MajorCool/

MAINTAINER=	andreas@FreeBSD.ORG

NO_BUILD=	yes
NO_PACKAGE=	"Too many questions"
USE_PERL5=	yes
WRKSRC=		${WRKDIR}

do-install:
		( cd ${WRKSRC}; ${SH} Configure )

.include <bsd.port.mk>
