# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	txt2tags
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
DISTNAME=	txt2tags_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:2 shebangfix
SHEBANG_FILES=	extras/html-update.sh txt2tags
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/txt2tags-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
