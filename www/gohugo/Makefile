# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.53
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
GH_TUPLE=	BurntSushi:locker:a6e239e:locker/src/github.com/BurntSushi/locker \
		BurntSushi:toml:a368813:BurntSushi_toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:v1.1.0:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2a:urlesc/src/github.com/PuerkitoBio/urlesc \
		alecthomas:assert:405dbfe:assert/src/github.com/alecthomas/assert \
		alecthomas:chroma:v0.6.0:chroma/src/github.com/alecthomas/chroma \
		alecthomas:colour:60882d9:colour/src/github.com/alecthomas/colour \
		alecthomas:repr:117648c:repr/src/github.com/alecthomas/repr \
		armon:consul-api:eb2c6b5:consul_api/src/github.com/armon/consul-api \
		bep:debounce:v1.1.0:debounce/src/github.com/bep/debounce \
		bep:gitmap:v1.0.0:gitmap/src/github.com/bep/gitmap \
		bep:go-tocss:v0.6.0:go_tocss/src/github.com/bep/go-tocss \
		chaseadamsio:goorgeous:v1.1.0:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cheekybits:is:68e9c06:cheekybits_is/src/github.com/cheekybits/is \
		coreos:etcd:v3.3.10:etcd/src/github.com/coreos/etcd \
		coreos:go-etcd:v2.0.0:go_etcd/src/github.com/coreos/go-etcd \
		coreos:go-semver:v0.2.0:go_semver/src/github.com/coreos/go-semver \
		cpuguy83:go-md2man:v1.0.8:go_md2man/src/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac:fnmatch/src/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:go_spew/src/github.com/davecgh/go-spew \
		disintegration:imaging:v1.5.0:imaging/src/github.com/disintegration/imaging \
		dlclark:regexp2:v1.1.6:regexp2/src/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:go_humanize/src/github.com/dustin/go-humanize \
		eknkc:amber:cdade1c:amber/src/github.com/eknkc/amber \
		fortytw2:leaktest:v1.2.0:leaktest/src/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:v1.4.7:fsnotify/src/github.com/fsnotify/fsnotify \
		gobwas:glob:v0.2.3:glob/src/github.com/gobwas/glob \
		gorilla:websocket:v1.4.0:websocket/src/github.com/gorilla/websocket \
		hashicorp:go-immutable-radix:v1.0.0:go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-uuid:v1.0.0:go_uuid/src/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.0:golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:mousetrap/src/github.com/inconshreveable/mousetrap \
		jdkato:prose:v1.1.0:prose/src/github.com/jdkato/prose \
		kr:pretty:v0.1.0:pretty/src/github.com/kr/pretty \
		kr:pty:v1.1.1:pty/src/github.com/kr/pty \
		kr:text:v0.1.0:kr_text/src/github.com/kr/text \
		kyokomi:emoji:v1.5.1:emoji/src/github.com/kyokomi/emoji \
		magefile:mage:v1.4.0:magefile_mage/src/github.com/magefile/mage \
		magiconair:properties:v1.8.0:properties/src/github.com/magiconair/properties \
		markbates:inflect:a12c3ae:inflect/src/github.com/markbates/inflect \
		matryer:try:9ac251b:try/src/github.com/matryer/try \
		mattn:go-isatty:v0.0.4:go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.3:go_runewidth/src/github.com/mattn/go-runewidth \
		miekg:mmark:v1.3.6:mmark/src/github.com/miekg/mmark \
		mitchellh:hashstructure:v1.0.0:hashstructure/src/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mapstructure/src/github.com/mitchellh/mapstructure \
		muesli:smartcrop:f6ebaa7:smartcrop/src/github.com/muesli/smartcrop \
		nfnt:resize:83c6a99:resize/src/github.com/nfnt/resize \
		nicksnyder:go-i18n:v1.10.0:go_i18n/src/github.com/nicksnyder/go-i18n \
		olekukonko:tablewriter:d4647c9:tablewriter/src/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.2.0:go_toml/src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:go_difflib/src/github.com/pmezard/go-difflib \
		russross:blackfriday:46c73eb:blackfriday/src/github.com/russross/blackfriday \
		sanity-io:litter:v1.1.0:litter/src/github.com/sanity-io/litter \
		sergi:go-diff:v1.0.0:sergi_go_diff/src/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:86672fc:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:v1.2.0:afero/src/github.com/spf13/afero \
		spf13:cast:v1.3.0:cast/src/github.com/spf13/cast \
		spf13:cobra:v0.0.3:cobra/src/github.com/spf13/cobra \
		spf13:fsync:12a01e6:fsync/src/github.com/spf13/fsync \
		spf13:jwalterweatherman:94f6ae3:jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:v1.0.3:pflag/src/github.com/spf13/pflag \
		spf13:viper:v1.3.1:viper/src/github.com/spf13/viper \
		stretchr:testify:04af852:testify/src/github.com/stretchr/testify \
		tdewolff:minify:v2.3.7:minify/src/github.com/tdewolff/minify \
		tdewolff:parse:v2.3.5:parse/src/github.com/tdewolff/parse \
		tdewolff:test:v1.0.0:tdewolff_test/src/github.com/tdewolff/test \
		ugorji:go:d75b2dc:ugorji_go/src/github.com/ugorji/go/codec \
		wellington:go-libsass:c636442:go_libsass/src/github.com/wellington/go-libsass \
		xordataexchange:crypt:b2862e3:xordataexchange_crypt/src/github.com/xordataexchange/crypt \
		yosssi:ace:v0.0.5:ace/src/github.com/yosssi/ace \
		golang:crypto:505ab14:crypto/src/golang.org/x/crypto \
		golang:image:c73c2af:image/src/golang.org/x/image \
		golang:net:161cd47:net/src/golang.org/x/net \
		golang:sync:1d60e46:golang_sync/src/golang.org/x/sync \
		golang:sys:70b957f:sys/src/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/src/golang.org/x/text \
		go-check:check:788fd78:go_check_check/src/gopkg.in/check.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/src/gopkg.in/yaml.v2

COMMIT_ID=	8fc339dc2529ff77e494a1c12cd1ff9fbcb880a4

OPTIONS_DEFINE=		MANPAGES EXTENDED

EXTENDED_DESC=		Enable SCSS/SASS support

OPTIONS_DEFAULT=	MANPAGES

EXTENDED_VARS=		CGO_ENABLED=1 BUILD_TAGS="-tags extended"
EXTENDED_VARS_OFF=	CGO_ENABLED=0

OPTIONS_SUB=		yes

GOENV=		GOPATH=${WRKSRC} CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" GOBIN=""
CGO_ENABLED=	0

PORTMANS=	hugo-config.1 hugo-convert-toJSON.1 hugo-convert-toTOML.1 \
		hugo-convert-toYAML.1 hugo-convert.1 hugo-env.1 \
		hugo-gen-autocomplete.1 hugo-gen-chromastyles.1 \
		hugo-gen-doc.1 hugo-gen-man.1 hugo-gen.1 \
		hugo-import-jekyll.1 hugo-import.1 hugo-list-drafts.1 \
		hugo-list-expired.1 hugo-list-future.1 hugo-list.1 \
		hugo-new-site.1 hugo-new-theme.1 hugo-new.1 hugo-server.1 \
		hugo-version.1 hugo.1

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
