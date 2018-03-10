# $FreeBSD$

PORTNAME=	with
DISTVERSION=	g20171025
CATEGORIES=	misc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command prefixing for continuous workflow using a single tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	mchav
GH_TAGNAME=	3d0ed3d

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/with \
		etc/bash_completion.d/with.bash-completion
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/with ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/with.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
