# New ports collection makefile for:    calc
# Version required:     2.9.3t6
# Date created:         3 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/16 23:19:07 asami Exp $
#

DISTNAME=	calc-2.9.3t6
PKGNAME=	calc-2.9.3
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/misc/4.4BSD-Lite/contrib/

MAINTAINER=	jmz@FreeBSD.org

CATEGORIES+=	math

pre-install:
	@mkdir -p ${PREFIX}/lib/calc/help
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
