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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WindowMaker dockable hardware monitor for FreeBSD

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmhm/wmhm

GNU_CONFIGURE=	yes
MAN8=		wmhm.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wmhm

post-install:
	${STRIP_CMD} ${PREFIX}/bin/wmhm

.include <bsd.port.mk>
