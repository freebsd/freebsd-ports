# New ports collection makefile for:   consolehm
# Version required:    1.0
# Date created:        27 September 1999
# Whom:                Mike Muir <mmuir@es.co.nz>
#
# $FreeBSD$
#

DISTNAME=	consolehm-1.0
CATEGORIES=	sysutils
MASTER_SITES= 	ftp://mongol.dhis.org/pub/consolehm/ \
		http://www.es.co.nz/~mmuir/

MAINTAINER=	mmuir@es.co.nz

WRKSRC=		${WRKDIR}/consolehm/consolehm

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		'consolehm requires intpm which is only available in 4.0-CURRENT.'
.endif

.include <bsd.port.post.mk>
