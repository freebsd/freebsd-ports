# New ports collection makefile for:	rblcheck
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	rblcheck
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTDOCS=	BUGS CHANGES CREDITS INSTALL PLATFORMS TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rblcheck
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/rblcheck
.endfor
.endif

.include <bsd.port.mk>
