# New ports collection makefile for:    calc
# Version required:     2.9.3t6
# Date created:         3 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.7 1996/11/18 11:32:07 asami Exp $
#

DISTNAME=	calc-2.9.3t6
PKGNAME=	calc-2.9.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/misc/4.4BSD-Lite/contrib/

MAINTAINER=	jmz@FreeBSD.org

MAN1=		calc.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/calc/help
	@${MKDIR} ${PREFIX}/man/man1

.include <bsd.port.mk>
