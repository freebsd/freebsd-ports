PORTNAME=	pass-coffin
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Password store extension to hide data inside an encrypted coffin
WWW=		https://github.com/ayushnix/pass-coffin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		pass:sysutils/password-store

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ayushnix
SHEBANG_FILES=	*.bash

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	md2roff:textproc/md2roff

do-build:
	${DO_NADA}

post-build-DOCS-on:
	${LOCALBASE}/bin/md2roff ${WRKSRC}/README.md

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/password-store/extensions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_SCRIPT} ${WRKSRC}/*.bash \
		${STAGEDIR}${PREFIX}/libexec/password-store/extensions
	${INSTALL_DATA} ${WRKSRC}/completion/pass-coffin.bash-completion \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
