# New ports collection makefile for:   pspp
# Date created:                        22 Apr 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	pspp
PORTVERSION=	0.2.4
CATEGORIES=	math
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pspp/ \
		ftp://pspp.stat.wisc.edu/pub/PSPP/

MAINTAINER=	john@coastalgeology.org

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

.include <bsd.port.post.mk>
