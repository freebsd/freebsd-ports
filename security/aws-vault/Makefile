# $FreeBSD$

PORTNAME=	aws-vault
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.0
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Vault for securely storing and accessing AWS credentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	99designs
GH_TUPLE=	\
		99designs:go-keychain:8e49817e8af4:99designs_go_keychain_1/vendor/github.com/keybase/go-keychain \
		99designs:keyring:v1.1.6:99designs_keyring/vendor/github.com/99designs/keyring \
		alecthomas:kingpin:b6657d9477a6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		aws:aws-sdk-go:v1.34.13:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		danieljoos:wincred:v1.1.0:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		dvsekhvalnov:jose2go:248326c1351b:dvsekhvalnov_jose2go/vendor/github.com/dvsekhvalnov/jose2go \
		go-ini:ini:v1.60.2:go_ini_ini/vendor/gopkg.in/ini.v1 \
		godbus:dbus:4481cbc300e2:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:d9f96fdee20d:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		gsterjov:go-libsecret:a6f4afe4910c:gsterjov_go_libsecret/vendor/github.com/gsterjov/go-libsecret \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mtibben:androiddnsfix:ff0280446354:mtibben_androiddnsfix/vendor/github.com/mtibben/androiddnsfix \
		mtibben:percent:v0.2.1:mtibben_percent/vendor/github.com/mtibben/percent \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey

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
