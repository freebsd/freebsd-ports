# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	pm-lib
PORTVERSION=	20091202
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH/procmail-lib
DISTNAME=	procmail-lib-2009.1202

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of procmail plug-in modules

LICENSE=	GPLv2

RUN_DEPENDS=	procmail:mail/procmail

NO_BUILD=	yes
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/pm-*.rc ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/article/index.txt \
		${STAGEDIR}${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/manual/index.txt \
		${STAGEDIR}${DOCSDIR}/manual.txt
	cd ${WRKSRC}/doc/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
