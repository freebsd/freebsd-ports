# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.1
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and flexible static site generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE=	BurntSushi:toml:a368813:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:0bcb03f:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2a:urlesc/src/github.com/PuerkitoBio/urlesc \
		alecthomas:chroma:e0f32fb:chroma/src/github.com/alecthomas/chroma \
		bep:gitmap:de8030e:gitmap/src/github.com/bep/gitmap \
		chaseadamsio:goorgeous:dcf1ef8:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cpuguy83:go-md2man:1d903dc:go_md2man/src/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac:fnmatch/src/github.com/danwakefield/fnmatch \
		davecgh:go-spew:346938d:go_spew/src/github.com/davecgh/go-spew \
		disintegration:imaging:dd50a3e:imaging/src/github.com/disintegration/imaging \
		dlclark:regexp2:487489b:regexp2/src/github.com/dlclark/regexp2 \
		eknkc:amber:cdade1c:amber/src/github.com/eknkc/amber \
		fortytw2:leaktest:7dad533:leaktest/src/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:c282820:fsnotify/src/github.com/fsnotify/fsnotify \
		gobwas:glob:bea32b9:glob/src/github.com/gobwas/glob \
		gorilla:websocket:ea4d1f6:websocket/src/github.com/gorilla/websocket \
		hashicorp:go-immutable-radix:8aac270:go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:0a025b7:golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:23c074d:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/src/github.com/inconshreveable/mousetrap \
		jdkato:prose:20d3663:prose/src/github.com/jdkato/prose \
		kyokomi:emoji:7e06b23:emoji/src/github.com/kyokomi/emoji \
		magefile:mage:2f97430:mage/src/github.com/magefile/mage \
		magiconair:properties:d419a98:properties/src/github.com/magiconair/properties \
		markbates:inflect:a12c3ae:inflect/src/github.com/markbates/inflect \
		mattn:go-runewidth:9e777a8:go_runewidth/src/github.com/mattn/go-runewidth \
		miekg:mmark:fd2f6c1:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:b4575ee:mapstructure/src/github.com/mitchellh/mapstructure \
		muesli:smartcrop:1db4849:smartcrop/src/github.com/muesli/smartcrop \
		nicksnyder:go-i18n:0dc1626:go_i18n/src/github.com/nicksnyder/go-i18n \
		olekukonko:tablewriter:96aac99:tablewriter/src/github.com/olekukonko/tablewriter \
		pelletier:go-toml:16398ba:go_toml/src/github.com/pelletier/go-toml \
		pmezard:go-difflib:792786c:go_difflib/src/github.com/pmezard/go-difflib \
		russross:blackfriday:4048872:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:86672fc:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:bb8f192:afero/src/github.com/spf13/afero \
		spf13:cast:acbeb36:cast/src/github.com/spf13/cast \
		spf13:cobra:b95ab73:cobra/src/github.com/spf13/cobra \
		spf13:fsync:12a01e6:fsync/src/github.com/spf13/fsync \
		spf13:jWalterWeatherman:7c0cea3:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		spf13:viper:25b30aa:viper/src/github.com/spf13/viper \
		stretchr:testify:b91bfb9:testify/src/github.com/stretchr/testify \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		golang:image:12117c1:image/src/golang.org/x/image \
		golang:net:5ccada7:net/src/golang.org/x/net \
		golang:sync:fd80eb9:sync/src/golang.org/x/sync \
		golang:sys:810d700:sys/src/golang.org/x/sys \
		golang:text:e19ae14:text/src/golang.org/x/text \
		go-yaml:yaml:d670f94:yaml/src/gopkg.in/yaml.v2

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

GOENV=		GOPATH=${WRKSRC} CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" GOBIN=""

PORTMANS=	hugo-benchmark.1 hugo-config.1 hugo-convert-toJSON.1 \
		hugo-convert-toTOML.1 hugo-convert-toYAML.1 hugo-convert.1 \
		hugo-env.1 hugo-gen-autocomplete.1 hugo-gen-chromastyles.1 \
		hugo-gen-doc.1 hugo-gen-man.1 hugo-gen.1 hugo-import-jekyll.1 \
		hugo-import.1 hugo-list-drafts.1 hugo-list-expired.1 \
		hugo-list-future.1 hugo-list.1 hugo-new-site.1 \
		hugo-new-theme.1 hugo-new.1 hugo-server.1 hugo-version.1 \
		hugo.1

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
