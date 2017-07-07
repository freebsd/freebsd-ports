# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	0.24.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and modern static website engine

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE=	BurntSushi:toml:8fb9fdc:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:b938d81:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:bbf7a2a:urlesc/src/github.com/PuerkitoBio/urlesc \
		bep:gitmap:de8030e:gitmap/src/github.com/bep/gitmap \
		bep:inflect:b896c45:inflect/src/github.com/bep/inflect \
		chaseadamsio:goorgeous:677defd:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cpuguy83:go-md2man:23709d0:go_md2man/src/github.com/cpuguy83/go-md2man \
		dchest:cssmin:fb8d9b4:cssmin/src/github.com/dchest/cssmin \
		eknkc:amber:5fa7895:amber/src/github.com/eknkc/amber \
		fortytw2:leaktest:7dad533:leaktest/src/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:4da3e2c:fsnotify/src/github.com/fsnotify/fsnotify \
		gorilla:websocket:a91eba7:websocket/src/github.com/gorilla/websocket \
		hashicorp:go-immutable-radix:30664b8:go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:0a025b7:golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:392dba7:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:76626ae:mousetrap/src/github.com/inconshreveable/mousetrap \
		kardianos:osext:ae77be6:osext/src/github.com/kardianos/osext \
		kr:fs:2788f0d:fs/src/github.com/kr/fs \
		kyokomi:emoji:ddd4753:emoji/src/github.com/kyokomi/emoji \
		magiconair:properties:51463bf:properties/src/github.com/magiconair/properties \
		miekg:mmark:f809cc9:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:d0303fe:mapstructure/src/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:3e70a1a:go_i18n/src/github.com/nicksnyder/go-i18n \
		pelletier:go-buffruneio:c37440a:go_buffruneio/src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:fe7536c:go_toml/src/github.com/pelletier/go-toml \
		pkg:errors:c605e28:errors/src/github.com/pkg/errors \
		pkg:sftp:a5f8514:sftp/src/github.com/pkg/sftp \
		russross:blackfriday:067529f:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:541ff5e:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:9be6508:afero/src/github.com/spf13/afero \
		spf13:cast:acbeb36:cast/src/github.com/spf13/cast \
		spf13:cobra:b4dbd37:cobra/src/github.com/spf13/cobra \
		spf13:fsync:12a01e6:fsync/src/github.com/spf13/fsync \
		spf13:jWalterWeatherman:0efa520:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		spf13:viper:c1de958:viper/src/github.com/spf13/viper \
		stretchr:testify:f6abca5:testify/src/github.com/stretchr/testify \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		golang:crypto:850760c:crypto/src/golang.org/x/crypto \
		golang:net:ddf80d0:net/src/golang.org/x/net \
		golang:sys:fb4cac3:sys/src/golang.org/x/sys \
		golang:text:9e2f80a:text/src/golang.org/x/text \
		go-yaml:yaml:cd8b52f:yaml/src/gopkg.in/yaml.v2 \
		davecgh:go-spew:04cdfd4:go_spew/src/github.com/davecgh/go-spew \
		pmezard:go-difflib:d8ed262:go_difflib/src/github.com/pmezard/go-difflib

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		MANPAGES

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
