PORTNAME=	pm-lib
PORTVERSION=	20091202
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH/procmail-lib
DISTNAME=	procmail-lib-2009.1202

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of procmail plug-in modules

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/license/COPYING.GNU-GPL

RUN_DEPENDS=	procmail:mail/procmail

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/pm-*.rc ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/article/index.txt \
		${STAGEDIR}${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/manual/index.txt \
		${STAGEDIR}${DOCSDIR}/manual.txt

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/doc/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
