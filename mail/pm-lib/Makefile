# ports collection makefile for:	pm-lib
# Date created:				14 November 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	pm-lib
PORTVERSION=	20091202
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	procmail-lib
DISTNAME=	procmail-lib-2009.1202

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	A collection of procmail plug-in modules

LICENSE=	GPLv2

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes
PORTDOCS=	*
PORTDATA=	*

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/pm-*.rc ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/article/index.txt ${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/manual/index.txt ${DOCSDIR}/manual.txt
	${COPYTREE_SHARE} ${WRKSRC}/doc/examples ${DOCSDIR}
.endif

.include <bsd.port.mk>
