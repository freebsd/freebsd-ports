# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	pm-lib
PORTVERSION=	20091202
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	procmail-lib
DISTNAME=	procmail-lib-2009.1202

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	A collection of procmail plug-in modules

LICENSE=	GPLv2

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes
PORTDOCS=	*
PORTDATA=	*

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/pm-*.rc ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/article/index.txt ${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/manual/index.txt ${DOCSDIR}/manual.txt
	cd ${WRKSRC}/doc/examples && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
