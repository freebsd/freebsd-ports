PORTNAME=	dehydrated
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1-6
DISTVERSIONSUFFIX=	-g4fd777e
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
SUB_FILES=	000.dehydrated.daily 000.dehydrated.weekly pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	BASH
OPTIONS_SINGLE=		SHELL
OPTIONS_SINGLE_SHELL=	BASH ZSH

BASH_DESC=	Use the Bourne Again shell (BASH)
ZSH_DESC=	Use the Z shell (ZSH)

BASH_RUN_DEPENDS=	bash:shells/bash
ZSH_RUN_DEPENDS=	zsh:shells/zsh

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
	@${MKDIR} ${STAGEDIR}${ETCDIR}/.acme-challenges \
		${STAGEDIR}${PREFIX}/etc/periodic/daily \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_DATA} ${WRKSRC}/docs/examples/config ${STAGEDIR}${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/hook.sh ${STAGEDIR}${ETCDIR}/hook.sh.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/domains.txt ${STAGEDIR}${ETCDIR}/domains.txt.sample
	${INSTALL_MAN} ${WRKSRC}/docs/man/dehydrated.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/000.dehydrated.daily ${STAGEDIR}${PREFIX}/etc/periodic/daily/000.dehydrated
	${INSTALL_SCRIPT} ${WRKDIR}/000.dehydrated.weekly ${STAGEDIR}${PREFIX}/etc/periodic/weekly/000.dehydrated
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/dehydrated

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.	for d in dns-verification domains_txt ecc hook_chain \
		per-certificate-config staging tls-alpn troubleshooting wellknown
		${INSTALL_DATA} ${WRKSRC}/docs/${d}.md ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
