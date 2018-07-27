# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.45.1
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and flexible static site generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
COMMIT_ID=	9f9695cf7b061afc0238e4a1948bd21dc0ef3eba
GH_TUPLE=	BurntSushi:locker:a6e239e:locker/src/github.com/BurntSushi/locker \
		BurntSushi:toml:a368813:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:0bcb03f:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2a:urlesc/src/github.com/PuerkitoBio/urlesc \
		alecthomas:assert:405dbfe:assert/src/github.com/alecthomas/assert \
		alecthomas:chroma:1b755a9:chroma/src/github.com/alecthomas/chroma \
		alecthomas:colour:60882d9:colour/src/github.com/alecthomas/colour \
		alecthomas:repr:f49988b:repr/src/github.com/alecthomas/repr \
		bep:debounce:844797f:debounce/src/github.com/bep/debounce \
		bep:gitmap:012701e:gitmap/src/github.com/bep/gitmap \
		bep:go-tocss:2abb118:go_tocss/src/github.com/bep/go-tocss \
		chaseadamsio:goorgeous:dcf1ef8:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cpuguy83:go-md2man:a65d4d2:go_md2man/src/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac:fnmatch/src/github.com/danwakefield/fnmatch \
		davecgh:go-spew:346938d:go_spew/src/github.com/davecgh/go-spew \
		disintegration:imaging:dd50a3e:imaging/src/github.com/disintegration/imaging \
		dlclark:regexp2:487489b:regexp2/src/github.com/dlclark/regexp2 \
		eknkc:amber:cdade1c:amber/src/github.com/eknkc/amber \
		fortytw2:leaktest:a5ef704:leaktest/src/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:c282820:fsnotify/src/github.com/fsnotify/fsnotify \
		gobwas:glob:5ccd90e:glob/src/github.com/gobwas/glob \
		gorilla:websocket:ea4d1f6:websocket/src/github.com/gorilla/websocket \
		hashicorp:go-immutable-radix:7f3cd43:go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:0fb14ef:golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:ef8a98b:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/src/github.com/inconshreveable/mousetrap \
		jdkato:prose:20d3663:prose/src/github.com/jdkato/prose \
		kyokomi:emoji:7e06b23:emoji/src/github.com/kyokomi/emoji \
		magefile:mage:2f97430:mage/src/github.com/magefile/mage \
		magiconair:properties:c3beff4:properties/src/github.com/magiconair/properties \
		markbates:inflect:a12c3ae:inflect/src/github.com/markbates/inflect \
		mattn:go-isatty:0360b2a:go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:9e777a8:go_runewidth/src/github.com/mattn/go-runewidth \
		miekg:mmark:fd2f6c1:mmark/src/github.com/miekg/mmark \
		mitchellh:hashstructure:2bca23e:hashstructure/src/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:00c29f5:mapstructure/src/github.com/mitchellh/mapstructure \
		muesli:smartcrop:f6ebaa7:smartcrop/src/github.com/muesli/smartcrop \
		nicksnyder:go-i18n:0dc1626:go_i18n/src/github.com/nicksnyder/go-i18n \
		olekukonko:tablewriter:b8a9be0:tablewriter/src/github.com/olekukonko/tablewriter \
		pelletier:go-toml:acdc450:go_toml/src/github.com/pelletier/go-toml \
		pmezard:go-difflib:792786c:go_difflib/src/github.com/pmezard/go-difflib \
		russross:blackfriday:11635eb:blackfriday/src/github.com/russross/blackfriday \
		sanity-io:litter:ae543b7:litter/src/github.com/sanity-io/litter \
		sergi:go-diff:1744e29:go_diff/src/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:86672fc:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:787d034:afero/src/github.com/spf13/afero \
		spf13:cast:8965335:cast/src/github.com/spf13/cast \
		spf13:cobra:a1f051b:cobra/src/github.com/spf13/cobra \
		spf13:fsync:12a01e6:fsync/src/github.com/spf13/fsync \
		spf13:jWalterWeatherman:7c0cea3:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		spf13:viper:b5e8006:viper/src/github.com/spf13/viper \
		stretchr:testify:12b6f73:testify/src/github.com/stretchr/testify \
		tdewolff:minify:8d72a41:minify/src/github.com/tdewolff/minify \
		tdewolff:parse:d739d6f:parse/src/github.com/tdewolff/parse \
		wellington:go-libsass:615eaa4:go_libsass/src/github.com/wellington/go-libsass \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		golang:image:f315e44:image/src/golang.org/x/image \
		golang:net:61147c4:net/src/golang.org/x/net \
		golang:sync:1d60e46:sync/src/golang.org/x/sync \
		golang:sys:3b87a42:sys/src/golang.org/x/sys \
		golang:text:2cb4393:text/src/golang.org/x/text \
		go-yaml:yaml:5420a8b:yaml/src/gopkg.in/yaml.v2

OPTIONS_DEFINE=		MANPAGES EXTENDED

EXTENDED_DESC=		Enable SCSS/SASS support

OPTIONS_DEFAULT=	MANPAGES

EXTENDED_VARS=		CGO_ENABLED=1 BUILD_TAGS="-tags extended"
EXTENDED_VARS_OFF=	CGO_ENABLED=0

OPTIONS_SUB=		yes

GOENV=		GOPATH=${WRKSRC} CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" GOBIN=""
CGO_ENABLED=	0

PORTMANS=	hugo-benchmark.1 hugo-config.1 hugo-convert-toJSON.1 \
		hugo-convert-toTOML.1 hugo-convert-toYAML.1 hugo-convert.1 \
		hugo-env.1 hugo-gen-autocomplete.1 hugo-gen-chromastyles.1 \
		hugo-gen-doc.1 hugo-gen-man.1 hugo-gen.1 hugo-import-jekyll.1 \
		hugo-import.1 hugo-list-drafts.1 hugo-list-expired.1 \
		hugo-list-future.1 hugo-list.1 hugo-new-site.1 \
		hugo-new-theme.1 hugo-new.1 hugo-server.1 hugo-version.1 \
		hugo.1

do-build:
	@(if [ -z "$${SOURCE_DATE_EPOCH}" ]; then\
		SOURCE_DATE_EPOCH=`grep TIMESTAMP ${DISTINFO_FILE} \
		  | ${SED} -e 's/[^0-9]//g'`; \
		SOURCE_DATE_EPOCH=`date -r $${SOURCE_DATE_EPOCH} "+%FT%TZ%z"`; \
	fi; \
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}; \
		${SETENV} ${MAKE_ENV} CGO_ENABLED=${CGO_ENABLED} ${GOENV} \
		${GO_CMD} build \
		-ldflags "\
		-s -w \
		-X github.com/gohugoio/hugo/hugolib.BuildDate=$${SOURCE_DATE_EPOCH} \
		-X github.com/gohugoio/hugo/hugolib.CommitHash=${COMMIT_ID}" \
		${BUILD_TAGS} \
		-o bin/${PORTNAME})

do-build-MANPAGES-on:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ./bin/${PORTNAME} gen man --dir man/man1/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
