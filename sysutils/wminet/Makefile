# New ports collection makefile for:   wminet
# Date created:        23 May 1999
# Whom:                Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=	wminet
PORTVERSION= 	2.0.2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.neotokyo.org/illusion/

MAINTAINER=	sk-ports@vegamuse.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/wminet.app/wminet

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/wminet
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wminet
.endif

.include <bsd.port.mk>
