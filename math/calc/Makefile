# New ports collection makefile for:    calc
# Date created:         3 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	calc
PORTVERSION=	2.11.2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.uu.net/pub/calc/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/math-packs/calc/ \
		ftp://ftp.batnet.com/pub/wombats/noll/ftp/pub/calc/
DISTNAME=	calc-2.11.2t1.0

MAINTAINER=	jmz@FreeBSD.org

MAN1=		calc.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/calc/help

.include <bsd.port.mk>
