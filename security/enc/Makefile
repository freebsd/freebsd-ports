PORTNAME=	enc
DISTVERSION=	1.1.3
PORTREVISION=	6
CATEGORIES=	security

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Modern and friendly CLI alternative to GnuPG
WWW=		https://github.com/life4/enc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	life4

GH_TUPLE=	ProtonMail:go-crypto:afb1ddc0824c:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		ProtonMail:go-mime:7d82a3887f2f:protonmail_go_mime/vendor/github.com/ProtonMail/go-mime \
		ProtonMail:gopenpgp:v2.7.4:protonmail_gopenpgp_v2/vendor/github.com/ProtonMail/gopenpgp/v2 \
		cloudflare:circl:v1.3.7:cloudflare_circl/vendor/github.com/cloudflare/circl \
		golang:crypto:v0.18.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:v0.6.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.16.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		matryer:is:v1.4.0:matryer_is/vendor/github.com/matryer/is \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

PLIST_FILES=	bin/enc

.include <bsd.port.mk>
