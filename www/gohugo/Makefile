# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.1
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and flexible static site generator

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE=	BurntSushi:toml:a368813:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:fd18e05:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2a:urlesc/src/github.com/PuerkitoBio/urlesc \
		alecthomas:chroma:02c4adc:chroma/src/github.com/alecthomas/chroma \
		bep:gitmap:de8030e:gitmap/src/github.com/bep/gitmap \
		chaseadamsio:goorgeous:7daffad:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cpuguy83:go-md2man:1d903dc:go_md2man/src/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac:fnmatch/src/github.com/danwakefield/fnmatch \
		dchest:cssmin:fb8d9b4:cssmin/src/github.com/dchest/cssmin \
		dlclark:regexp2:7632a26:regexp2/src/github.com/dlclark/regexp2 \
		eknkc:amber:4ed0bf7:amber/src/github.com/eknkc/amber \
		fortytw2:leaktest:3b724c3:leaktest/src/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:4da3e2c:fsnotify/src/github.com/fsnotify/fsnotify \
		gorilla:websocket:4201258:websocket/src/github.com/gorilla/websocket \
		hashicorp:go-immutable-radix:8aac270:go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:0a025b7:golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:68e816d:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/src/github.com/inconshreveable/mousetrap \
		jdkato:prose:2f88f08:prose/src/github.com/jdkato/prose \
		kardianos:osext:ae77be6:osext/src/github.com/kardianos/osext \
		kyokomi:emoji:ddd4753:emoji/src/github.com/kyokomi/emoji \
		magiconair:properties:8d7837e:properties/src/github.com/magiconair/properties \
		markbates:inflect:ea17041:inflect/src/github.com/markbates/inflect \
		miekg:mmark:057eb9e:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:d0303fe:mapstructure/src/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:0dc1626:go_i18n/src/github.com/nicksnyder/go-i18n \
		pelletier:go-toml:2009e44:go_toml/src/github.com/pelletier/go-toml \
		russross:blackfriday:6d1ef89:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:86672fc:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:8a6ade7:afero/src/github.com/spf13/afero \
		spf13:cast:acbeb36:cast/src/github.com/spf13/cast \
		spf13:cobra:0dacccf:cobra/src/github.com/spf13/cobra \
		spf13:fsync:12a01e6:fsync/src/github.com/spf13/fsync \
		spf13:jWalterWeatherman:12bd96e:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:be7121d:pflag/src/github.com/spf13/pflag \
		spf13:viper:d9cca5e:viper/src/github.com/spf13/viper \
		stretchr:testify:890a5c3:testify/src/github.com/stretchr/testify \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		golang:image:334384d:image/src/golang.org/x/image \
		golang:net:0a93976:net/src/golang.org/x/net \
		golang:sys:314a259:sys/src/golang.org/x/sys \
		golang:text:1cbadb4:text/src/golang.org/x/text \
		go-yaml:yaml:eb3733d:yaml/src/gopkg.in/yaml.v2 \
		davecgh:go-spew:04cdfd4:go_spew/src/github.com/davecgh/go-spew \
		pmezard:go-difflib:d8ed262:go_difflib/src/github.com/pmezard/go-difflib

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_DESC=	Build and/or install manual pages

GOENV=		GOPATH=${WRKSRC} CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" GOBIN=""

PORTMANS=	hugo-benchmark.1 hugo-config.1 hugo-convert-toJSON.1 \
		hugo-convert-toTOML.1 hugo-convert-toYAML.1 hugo-convert.1 \
		hugo-env.1 hugo-gen-autocomplete.1 hugo-gen-doc.1 hugo-gen-man.1 \
		hugo-gen.1 hugo-import-jekyll.1 hugo-import.1 hugo-list-drafts.1 \
		hugo-list-expired.1 hugo-list-future.1 hugo-list.1 hugo-new-site.1 \
		hugo-new-theme.1 hugo-new.1 hugo-server.1 hugo-undraft.1 \
		hugo-version.1 hugo.1

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && \
	${SETENV} ${MAKE_ENV} ${GOENV} ${GO_CMD} build -o bin/${PORTNAME}

do-build-MANPAGES-on:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ./bin/${PORTNAME} gen man --dir man/man1/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
