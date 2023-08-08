PORTNAME=	dehydrated
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1-5
DISTVERSIONSUFFIX=	-ge3ef43c
CATEGORIES=	security

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Pure BASH/ZSH Lets Encrypt client
WWW=		https://dehydrated.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USES=		shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	dehydrated-io
SHEBANG_FILES=	docs/examples/hook.sh dehydrated

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	000.dehydrated pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	BASH
OPTIONS_SINGLE=		SHELL
OPTIONS_SINGLE_SHELL=	BASH ZSH

BASH_DESC=	Use the Bourne Again shell (BASH)
ZSH_DESC=	Use the Z shell (ZSH)

BASH_RUN_DEPENDS=	bash:shells/bash
ZSH_RUN_DEPENDS=	zsh:shells/zsh
PERIODIC_DIRS=		etc/periodic/weekly
PERIODIC_FILES=		000.dehydrated

post-patch:
.	for f in docs/examples/config dehydrated
		@${REINPLACE_CMD} 's|/var/www/dehydrated|${PREFIX}/www/dehydrated|' \
		    ${WRKSRC}/${f}
.	endfor

post-patch-ZSH-on:
.	for p in docs/examples/hook.sh dehydrated
		@${REINPLACE_CMD} '1 s/bash/zsh/' ${WRKSRC}/${p}
.	endfor

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/.acme-challenges ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/config ${STAGEDIR}${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/hook.sh ${STAGEDIR}${ETCDIR}/hook.sh.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/domains.txt ${STAGEDIR}${ETCDIR}/domains.txt.sample
	${INSTALL_MAN} ${WRKSRC}/docs/man/dehydrated.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/dehydrated

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.	for d in dns-verification domains_txt ecc hook_chain \
		per-certificate-config staging tls-alpn troubleshooting wellknown
		${INSTALL_DATA} ${WRKSRC}/docs/${d}.md ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
