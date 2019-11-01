# $FreeBSD$

PORTNAME=	hcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Official Hetzner Cloud command-line interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	hetznercloud
GH_PROJECT=	cli
GH_TUPLE=	\
		dustin:go-humanize:bb3d318650d4:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:structs:ebf56d35bba7:fatih_structs/vendor/github.com/fatih/structs \
		golang:crypto:d6449816ce06:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:3b87a42e500a:golang_sys/vendor/golang.org/x/sys \
		gosuri:uilive:ac356e6e42cd:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:d0567a9d84a1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		hetznercloud:hcloud-go:v1.14.0:hetznercloud_hcloud_go/vendor/github.com/hetznercloud/hcloud-go \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pelletier:go-toml:v1.1.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:cobra:615425954c3b:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		thcyron:uiprogress:25e98ffb0e98:thcyron_uiprogress/vendor/github.com/thcyron/uiprogress

GO_TARGET=	./cmd/hcloud

PLIST_FILES=	bin/hcloud

.include <bsd.port.mk>
