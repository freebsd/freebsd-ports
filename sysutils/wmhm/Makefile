# New ports collection makefile for:   wmhm
# Version required:    1.1
# Date created:        21 September 1999
# Whom:                Mike Muir <mmuir@es.co.nz>
#
# $FreeBSD$
#

DISTNAME=	wmhm-1.1
CATEGORIES=	sysutils windowmaker
MASTER_SITES= 	ftp://mongol.dhis.org/pub/wmhm/ \
		http://www.es.co.nz/~mmuir/

MAINTAINER=	mmuir@es.co.nz

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmhm/wmhm

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
FORBIDDEN=	'wmhm requires intpm which is only available in 4.0-CURRENT'
.endif

.include <bsd.port.post.mk>
