# New ports collection makefile for:	plconfig
# Date created:		Mon Jan 27 12:34:34 PST 2003
# Whom:			Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	plconfig
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neon1.net/prog/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	Tool for configuring HomePlug powerline bridges

#WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	plconfig

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
