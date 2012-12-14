# New ports collection makefile for:	afuse
# Date created: 			03 March 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$
#

PORTNAME=	afuse
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	avl@FreeBSD.org
COMMENT=	An automounting file system implemented in user-space using FUSE

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

USE_FUSE=	yes
USE_PKGCONFIG=	yes

MAN1=		afuse.1

.if !defined(NOPORTDOCS)
SUB_FILES=	pkg-message
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
