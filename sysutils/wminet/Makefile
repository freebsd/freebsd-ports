# New ports collection makefile for:   wminet
# Date created:        23 May 1999
# Whom:                Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=	wminet
PORTVERSION=	2.0.2
CATEGORIES=	sysutils windowmaker
# All previous master sites no longer carry the tarball
# MASTER_SITES=

MAINTAINER=	sk-ports@vegamuse.org

WRKSRC=		${WRKDIR}/wminet.app/wminet

USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wminet
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wminet
.endif

.include <bsd.port.mk>
