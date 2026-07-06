PORTNAME=	languagetool
DISTVERSION=	6.6
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	https://languagetool.org/download/
DISTNAME=	LanguageTool-${DISTVERSION}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Style and grammar checker for more than 25 languages
WWW=		https://languagetool.org \
		https://github.com/languagetool-org/languagetool

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	javavm:java/javavmwrapper

USES=		cpe java:run zip
JAVA_VERSION=	17+
USE_RC_SUBR=	languagetool

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	languagetool-cli languagetool-gui pkg-message

USERS=		languagetool
GROUPS=		languagetool

PORTDOCS=	CHANGES.md CHANGES.txt README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/testrules.bat ${WRKSRC}/testrules.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! -name CHANGES.md ! -name CHANGES.txt ! -name README.md")
	${INSTALL_SCRIPT} ${WRKDIR}/languagetool-cli \
		${STAGEDIR}${PREFIX}/bin/languagetool
	${INSTALL_SCRIPT} ${WRKDIR}/languagetool-gui \
		${STAGEDIR}${PREFIX}/bin/languagetool-gui
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/server.properties.sample \
		${STAGEDIR}${ETCDIR}/server.properties.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
