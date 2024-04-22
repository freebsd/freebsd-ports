PORTNAME=		tmux-xpanes
DISTVERSIONPREFIX=	v
DISTVERSION=		4.2.0
CATEGORIES=		sysutils

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Ultimate terminal divider powered by tmux
WWW=		https://github.com/greymd/tmux-xpanes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash tmux>0:sysutils/tmux
TEST_DEPENDS=	shunit2>0:devel/shunit2

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	greymd
SHEBANG_FILES=	${WRKSRC}/bin/xpanes

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} 's|XP_SHELL="/usr/bin/env bash"|XP_SHELL="${bash_CMD}"|' \
		${WRKSRC}/bin/xpanes

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} bin/xpanes ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} man/xpanes.1 ${STAGEDIR}${PREFIX}/share/man/man1
	cd ${WRKSRC} && ${INSTALL_DATA} completion/zsh/_xpanes \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} README.md ${STAGEDIR}${DOCSDIR}

do-test:
	${REINPLACE_CMD} 's|$${THIS_DIR}/shunit2|${LOCALBASE}/bin|' \
		${WRKSRC}/test/cases_smoke.sh
	cd ${WRKSRC}/test && ./cases_smoke.sh

.include <bsd.port.mk>
