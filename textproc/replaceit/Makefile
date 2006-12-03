# New ports collection makefile for:	replaceit
# Date created:				Fri Aug 17 20:15:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	replaceit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://pldaniels.com/replaceit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A light replacement to the combination of sed/awk/grep/head/tail

PLIST_FILES=	bin/replaceit
PORTDOCS=	CHANGELOG INSTALL LICENSE README

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/replaceit ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
