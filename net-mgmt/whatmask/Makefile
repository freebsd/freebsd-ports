# New ports collection makefile for:	whatmask
# Date created:			May 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	whatmask
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/whatmask/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily convert between three common subnet mask notations

GNU_CONFIGURE=	yes

MAN1=		whatmask.1
DOCS=		AUTHORS ChangeLog README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
