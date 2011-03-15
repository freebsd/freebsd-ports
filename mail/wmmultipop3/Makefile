# New ports collection makefile for:	wmmultipop3
# Date created:				Fri Sep 28 16:25:34 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmmultipop3
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://bart.sm.luth.se/~dansun-8/software/wmMultiPop3/
DISTNAME=	wmMultiPop3-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A WindowMaker dockapp that checks multiple pop3 accounts for new mail

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
USE_XORG=	xpm

DOC_FILES=	ChangeLog INSTALL README

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/wmmultipop3 ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
