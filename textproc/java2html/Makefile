# New ports collection makefile for:	java2html
# Version required:			0.4
# Date created:				21 March 1999
# Whom:					Martin Kammerhofer
#
# $Id$
#

DISTNAME=		java2html-0.4
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net

USE_AUTOCONF=		yes

MAN1=			java2html.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/java2html
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/java2html
	${INSTALL_MAN} ${WRKSRC}/NEWS    ${PREFIX}/share/doc/java2html
	${INSTALL_MAN} ${WRKSRC}/README  ${PREFIX}/share/doc/java2html
.endif

.include <bsd.port.mk>
