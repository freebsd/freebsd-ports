# New ports collection makefile for:	wmmon
# Date created:		27 November 1998
# Whom:			Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	wmmon
PORTVERSION=	1.0b2
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WindowMaker dockable system load/performance monitor

DEPRECATED=	no longer available from mastersite
EXPIRATION_DATE=2006-11-05

WRKSRC=		${WRKDIR}/wmmon.app/wmmon

USE_X_PREFIX=	yes
USE_XPM=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/wmmon
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmmon
.endif

.include <bsd.port.mk>
