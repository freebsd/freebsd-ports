# New ports collection makefile for:   wminet
# Date created:        23 May 1999
# Whom:                Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=	wminet
PORTVERSION=	2.0.3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.neotokyo.org/illusion/downloads/

MAINTAINER=	sk-ports@vegamuse.org
COMMENT=	Window Maker dockable inetd monitor

WRKSRC=		${WRKDIR}/wminet.app/wminet

USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../HINTS ${DOCSDIR}
.endif

.include <bsd.port.mk>
