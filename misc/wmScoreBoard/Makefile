# New ports collection makefile for:	wmScoreBoard
# Date created:				Sun Jun 24 17:08:15 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmScoreBoard
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Window Maker dockapp that display game scores from excite

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in BUGS CHANGES HINTS README
	@${INSTALL_DATA} ${WRKSRC}/../${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
