# $FreeBSD$

PORTNAME=	gobgp
PORTVERSION=	1.28
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
GH_TUPLE=	BurntSushi:toml:b26d9c3:toml/../src/github.com/BurntSushi/toml \
		armon:go-radix:1fca145:radix/../src/github.com/armon/go-radix \
		davecgh:go-spew:346938d:spew/../src/github.com/davecgh/go-spew \
		dgryski:go-farm:ac7624e:farm/../src/github.com/dgryski/go-farm \
		eapache:channels:47238d5:channels/../src/github.com/eapache/channels \
		eapache:queue:ded5959:queue/../src/github.com/eapache/queue \
		fsnotify:fsnotify:629574c:fsnotify/../src/github.com/fsnotify/fsnotify \
		golang:protobuf:748d386:protobuf/../src/github.com/golang/protobuf \
		hashicorp:hcl:392dba7:hcl/../src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/../src/github.com/inconshreveable/mousetrap \
		influxdata:influxdb:5887e92:influxdb/../src/github.com/influxdata/influxdb \
		jessevdk:go-flags:96dc062:flags/../src/github.com/jessevdk/go-flags \
		kr:pretty:cfb55aa:pretty/../src/github.com/kr/pretty \
		kr:text:7cafcd8:krtext/../src/github.com/kr/text \
		magiconair:properties:be5ece7:properties/../src/github.com/magiconair/properties \
		mitchellh:mapstructure:d0303fe:mapstructure/../src/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:c37440a:buffruneio/../src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:5ccdfb1:toml/../src/github.com/pelletier/go-toml \
		pmezard:go-difflib:792786c:difflib/../src/github.com/pmezard/go-difflib \
		satori:go.uuid:36e9d2e:uuid/../src/github.com/satori/go.uuid \
		sirupsen:logrus:a3f95b5:logrus/../src/github.com/sirupsen/logrus \
		spf13:afero:9be6508:afero/../src/github.com/spf13/afero \
		spf13:cast:acbeb36:cast/../src/github.com/spf13/cast \
		spf13:cobra:b26b538:cobra/../src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:0efa520:jwalterweatherman/../src/github.com/spf13/jwalterweatherman \
		spf13:pflag:e57e3ee:pflag/../src/github.com/spf13/pflag \
		spf13:viper:25b30aa:viper/../src/github.com/spf13/viper \
		stretchr:testify:69483b4:testify/../src/github.com/stretchr/testify \
		vishvananda:netlink:a956595:netlink/../src/github.com/vishvananda/netlink \
		vishvananda:netns:86bef33:netns/../src/github.com/vishvananda/netns \
		golang:net:f5079bd:gonet/../src/golang.org/x/net \
		golang:sys:e312636:gosys/../src/golang.org/x/sys \
		golang:text:3bd178b:gotext/../src/golang.org/x/text \
		google:go-genproto:09f6ed2:genproto/../src/google.golang.org/genproto \
		grpc:grpc-go:b8669c3:grpc/../src/google.golang.org/grpc \
		go-tomb:tomb:d5d1b58:tombv2/../src/gopkg.in/tomb.v2 \
		go-yaml:yaml:25c4ec8:yamlv2/../src/gopkg.in/yaml.v2 \
		golang:crypto:5119cf5:gocrypto/../src/golang.org/x/crypto

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
