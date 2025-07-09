PORTNAME=	aws-vault
DISTVERSIONPREFIX=	v
DISTVERSION=	6.6.2
PORTREVISION=	19
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vault for securely storing and accessing AWS credentials
WWW=		https://github.com/99designs/aws-vault

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/99designs/aws-vault/v6
GO_BUILDFLAGS=	-ldflags="-s -w -X main.Version=${PORTVERSION}"

PORTDOCS=	README.md USAGE.md

OPTIONS_DEFINE=	DOCS YUBIKEY
OPTIONS_SUB=	yes

YUBIKEY_DESC=	Install Yubikey IAM helper script

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completions/bash/aws-vault.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/contrib/completions/fish/aws-vault.fish ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/contrib/completions/zsh/aws-vault.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-YUBIKEY-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/scripts/aws-iam-create-yubikey-mfa.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
