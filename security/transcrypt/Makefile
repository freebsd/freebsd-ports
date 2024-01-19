PORTNAME=	transcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
CATEGORIES=	security

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Transparently encrypt files within a git repository
WWW=		https://github.com/elasticdog/transcrypt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		git:devel/git \
		gpg2:security/gnupg \
		xxd:sysutils/xxd
TEST_DEPENDS=	bats:devel/bats-core

USE_GITHUB=	yes
GH_ACCOUNT=	elasticdog

NO_BUILD=	yes

PLIST_FILES=	bin/transcrypt \
		man/man1/transcrypt.1.gz \
		share/bash-completion/completions/transcrypt \
		share/zsh/site-functions/_transcrypt

post-patch:
	${REINPLACE_CMD} -e 's/\(darwin\*\))/\1|${OSTYPE}\*)/1' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions && \
		${INSTALL_DATA} ${WRKSRC}/contrib/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

# 53 tests, 0 failures
do-test:
	${LOCALBASE}/bin/bats ${WRKSRC}/tests

.include <bsd.port.mk>
