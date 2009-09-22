# New ports collection makefile for:    ua
# Date created:         13 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ua
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	https://oss.euedge.com/downloads/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Finds sets of identical files

GNU_CONFIGURE=	yes

MAN1=	kua.1 ua.1
PLIST_FILES=	bin/kua bin/ua
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
