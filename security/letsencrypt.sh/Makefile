# $FreeBSD$

PORTNAME=	letsencrypt.sh
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sascha@root-login.org
COMMENT=	Pure BASH/ZSH Lets Encrypt client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	lukas2511

OPTIONS_SINGLE=	SHELL
OPTIONS_SINGLE_SHELL=	BASH ZSH
BASH_DESC=	Use the Bourne Again shell (BASH)
ZSH_DESC=	Use the Z shell (ZSH)

OPTIONS_DEFAULT=	BASH

NO_ARCH=	yes
NO_BUILD=	yes
USES=		shebangfix

BASH_RUN_DEPENDS=	bash:shells/bash
ZSH_RUN_DEPENDS=	zsh:shells/zsh

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	000.letsencrypt.sh

PLIST_DIRS=	%%ETCDIR%%/.acme-challenges
PLIST_FILES=	bin/letsencrypt.sh \
		%%ETCDIR%%/config.sh.example \
		%%ETCDIR%%/hook.sh.example \
		%%ETCDIR%%/domains.txt.example \
		${PERIODIC_DIRS}/000.letsencrypt.sh
PORTDOCS_PLIST_FILES=	%%PORTDOCS%%%%DOCSDIR%%/README.md

SUB_FILES=	000.letsencrypt.sh pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}
PORTDOCS=	README.md

SHEBANG_FILES=	config.sh.example hook.sh.example letsencrypt.sh

post-patch-ZSH-on:
.	for p in config.sh.example hook.sh.example letsencrypt.sh
	${REINPLACE_CMD} '1 s/bash/zsh/' ${WRKSRC}/${p}
.	endfor

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/.acme-challenges ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_DATA} ${WRKSRC}/config.sh.example ${STAGEDIR}${ETCDIR}/config.sh.example
	${INSTALL_DATA} ${WRKSRC}/hook.sh.example ${STAGEDIR}${ETCDIR}/hook.sh.example
	${INSTALL_DATA} ${WRKSRC}/domains.txt.example ${STAGEDIR}${ETCDIR}/domains.txt.example
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
