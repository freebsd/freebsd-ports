# $FreeBSD$

PORTNAME=	gobgp
PORTVERSION=	2.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net
DIST_SUBDIR=	gobgp

MAINTAINER=	nork@ninth-nine.com
COMMENT=	BGP implementation in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/gobgp \
		./cmd/gobgpd:${PREFIX}/libexec/gobgpd
GH_ACCOUNT=	osrg
PLIST_FILES=	bin/gobgp libexec/gobgpd
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		coreos:go-systemd:95778dfbb74e:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-farm:ac7624ea8da3:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		eapache:channels:v1.1.0:eapache_channels/vendor/github.com/eapache/channels \
		eapache:queue:v1.0.2:eapache_queue/vendor/github.com/eapache/queue \
		fsnotify:fsnotify:v1.4.2:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:25c4ec802a7d:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.0.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:09f6ed296fc6:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.5.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:392dba7d905e:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jessevdk:go-flags:v1.3.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		k-sone:critbitgo:48c9e1530131:k_sone_critbitgo/vendor/github.com/k-sone/critbitgo \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		magiconair:properties:v1.7.3:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:d0303fe80992:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:v0.2.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.0.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sirupsen:logrus:a3f95b5c4235:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:9be650865eab:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.1.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:b26b538f6930:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:0efa5202c046:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.0:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.0.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.1.4:stretchr_testify/vendor/github.com/stretchr/testify \
		vishvananda:netlink:a95659537721:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:86bef332bfc3:vishvananda_netns/vendor/github.com/vishvananda/netns
OPTIONS_DEFINE=	BASH ZSH
OPTIONS_DEFAULT=BASH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/gobgp-completion.bash \
			etc/bash_completion.d/gobgp-dynamic-completion.bash \
			etc/bash_completion.d/gobgp-static-completion.bash
ZSH_PLIST_FILES=	share/zsh/site-functions/_gobgp

USE_RC_SUBR=	gobgpd
SUB_FILES=	gobgpd

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/gobgp*-completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/zsh/_gobgp ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
