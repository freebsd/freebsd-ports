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

WRKSRC=		${WRKDIR}/wmhm/wmhm

GNU_CONFIGURE=	yes
MAN8=		wmhm.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wmhm
USE_X_PREFIX=	yes
USE_XPM=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/wmhm

.include <bsd.port.post.mk>
