PORTNAME=	git-secret
DISTVERSION=	0.2.5
CATEGORIES=	security

MAINTAINER=	mail@sobolevn.me
COMMENT=	Bash tool to store your private data inside a git repository

LICENSE=	MIT
#MASTER_SITES=	https://github.com/sobolevn/git-secret/archive/

RUN_DEPENDS=	bash:shells/bash gawk:lang/gawk git:devel/git gpg2:security/gnupg

USE_GITHUB=	yes
GH_ACCOUNT=	sobolevn
GH_PROJECT=	git-secret
GH_TAGNAME=	94d5ae4

NO_ARCH=	yes

SCRIPTS=	git-secret
ALL_TARGET=	git-secret

post-extract:
	@cd ${WRKSRC} && ${CAT} src/version.sh src/_utils/*.sh src/commands/*.sh src/main.sh > git-secret

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-secret ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man7/*.7 ${STAGEDIR}${PREFIX}/man/man7/

.include <bsd.port.mk>
