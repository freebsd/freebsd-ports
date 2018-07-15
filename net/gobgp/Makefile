# $FreeBSD$

PORTNAME=	gobgp
PORTVERSION=	1.33
DISTVERSIONPREFIX=	v
CATEGORIES=	net
DIST_SUBDIR=	gobgp

MAINTAINER=	nork@ninth-nine.com
COMMENT=	BGP implementation in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/gobgp \
		${GO_PKGNAME}/gobgpd
USE_GITHUB=	yes
GH_ACCOUNT=	osrg:DEFAULT
GH_TUPLE=	BurntSushi:toml:a368813:toml/../src/github.com/BurntSushi/toml \
		armon:go-radix:1fca145:radix/../src/github.com/armon/go-radix \
		davecgh:go-spew:8991bc2:spew/../src/github.com/davecgh/go-spew \
		dgryski:go-farm:2de3383:farm/../src/github.com/dgryski/go-farm \
		eapache:channels:47238d5:channels/../src/github.com/eapache/channels \
		eapache:queue:093482f:queue/../src/github.com/eapache/queue \
		fsnotify:fsnotify:c282820:fsnotify/../src/github.com/fsnotify/fsnotify \
		golang:protobuf:14aad3d:protobuf/../src/github.com/golang/protobuf \
		hashicorp:hcl:ef8a98b:hcl/../src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/../src/github.com/inconshreveable/mousetrap \
		influxdata:influxdb:62ab18a:influxdb/../src/github.com/influxdata/influxdb \
		jessevdk:go-flags:1c38ed7:flags/../src/github.com/jessevdk/go-flags \
		kr:pretty:73f6ac0:pretty/../src/github.com/kr/pretty \
		kr:text:e2ffdb1:krtext/../src/github.com/kr/text \
		magiconair:properties:c235336:properties/../src/github.com/magiconair/properties \
		mitchellh:mapstructure:f15292f:mapstructure/../src/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:e2f66f8:buffruneio/../src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:c01d127:toml/../src/github.com/pelletier/go-toml \
		pmezard:go-difflib:792786c:difflib/../src/github.com/pmezard/go-difflib \
		satori:go.uuid:36e9d2e:uuid/../src/github.com/satori/go.uuid \
		sirupsen:logrus:9205268:logrus/../src/github.com/sirupsen/logrus \
		spf13:afero:787d034:afero/../src/github.com/spf13/afero \
		spf13:cast:8965335:cast/../src/github.com/spf13/cast \
		spf13:cobra:a114f31:cobra/../src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:7c0cea3:jwalterweatherman/../src/github.com/spf13/jwalterweatherman \
		spf13:pflag:3ebe029:pflag/../src/github.com/spf13/pflag \
		spf13:viper:d493c32:viper/../src/github.com/spf13/viper \
		stretchr:testify:f35b8ab:testify/../src/github.com/stretchr/testify \
		vishvananda:netlink:d77c86a:netlink/../src/github.com/vishvananda/netlink \
		vishvananda:netns:be1fbed:netns/../src/github.com/vishvananda/netns \
		golang:net:db08ff0:gonet/../src/golang.org/x/net \
		golang:sys:ac767d6:gosys/../src/golang.org/x/sys \
		golang:text:0605a83:gotext/../src/golang.org/x/text \
		google:go-genproto:e92b116:genproto/../src/google.golang.org/genproto \
		grpc:grpc-go:168a619:grpc/../src/google.golang.org/grpc \
		go-tomb:tomb:d5d1b58:tombv2/../src/gopkg.in/tomb.v2 \
		go-yaml:yaml:5420a8b:yamlv2/../src/gopkg.in/yaml.v2 \
		golang:crypto:a49355c:gocrypto/../src/golang.org/x/crypto

PLIST_FILES=	bin/gobgp libexec/gobgpd

OPTIONS_DEFINE=	BASH ZSH
OPTIONS_DEFAULT=BASH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/gobgp-completion.bash \
			etc/bash_completion.d/gobgp-dynamic-completion.bash \
			etc/bash_completion.d/gobgp-static-completion.bash
ZSH_PLIST_FILES=	share/zsh/site-functions/_gobgp

USE_RC_SUBR=	gobgpd
SUB_FILES=	gobgpd

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/gobgp  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/gobgpd ${STAGEDIR}${PREFIX}/libexec

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/gobgp*-completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/zsh/_gobgp ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
