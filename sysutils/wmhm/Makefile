# New ports collection makefile for:   wmhm
# Date created:        21 September 1999
# Whom:                Mike Muir <mmuir@es.co.nz>
#
# $FreeBSD$
#

PORTNAME=	wmhm
PORTVERSION=	1.46
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	mmuir@cwnet.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmhm/wmhm

GNU_CONFIGURE=	yes
MAN8=		wmhm.8
MANCOMPRESSED=	yes

post-install:
	strip ${PREFIX}/bin/wmhm

.include <bsd.port.mk>
