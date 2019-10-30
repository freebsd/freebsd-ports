# $FreeBSD$

PORTNAME=	aws-vault
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.1
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Vault for securely storing and accessing AWS credentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	99designs
GH_TUPLE=	\
		99designs:go-keychain:8e49817e8af4:99designs_go_keychain/vendor/github.com/keybase/go-keychain \
		99designs:keyring:v1.1.3:99designs_keyring/vendor/github.com/99designs/keyring \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		aws:aws-sdk-go:v1.25.17:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		danieljoos:wincred:v1.0.2:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		dvsekhvalnov:jose2go:7f401d37b68a:dvsekhvalnov_jose2go/vendor/github.com/dvsekhvalnov/jose2go \
		go-ini:ini:v1.49.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		godbus:dbus:4481cbc300e2:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:f8518d3b3627:golang_sys/vendor/golang.org/x/sys \
		gsterjov:go-libsecret:a6f4afe4910c:gsterjov_go_libsecret/vendor/github.com/gsterjov/go-libsecret \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		skratchdot:open-golang:79abb63cd66e:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang

GO_BUILDFLAGS=	-ldflags="-s -w -X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/aws-vault \
		share/zsh/site-functions/_aws-vault

PORTDOCS=	README.md USAGE.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/bash/aws-vault ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_aws-vault ${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} ./...

.include <bsd.port.mk>
