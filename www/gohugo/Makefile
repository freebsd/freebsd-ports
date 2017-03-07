# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	0.19
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and modern static website engine

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.5.0:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	spf13
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE=	BurntSushi:toml:9906417:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:0bcb03f:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:5bd2802:urlesc/src/github.com/PuerkitoBio/urlesc \
		bep:gitmap:dcb907b:gitmap/src/github.com/bep/gitmap \
		bep:inflect:b896c45:inflect/src/github.com/bep/inflect \
		chaseadamsio:goorgeous:054aba6:goorgeous/src/github.com/chaseadamsio/goorgeous \
		cpuguy83:go-md2man:a65d4d2:go_md2man/src/github.com/cpuguy83/go-md2man \
		dchest:cssmin:fb8d9b4:cssmin/src/github.com/dchest/cssmin \
		eknkc:amber:9be5e8a:amber/src/github.com/eknkc/amber \
		fsnotify:fsnotify:7d7316e:fsnotify/src/github.com/fsnotify/fsnotify \
		gorilla:websocket:b258b4f:websocket/src/github.com/gorilla/websocket \
		hashicorp:hcl:630949a:hcl/src/github.com/hashicorp/hcl \
		kardianos:osext:9b883c5:osext/src/github.com/kardianos/osext \
		kyokomi:emoji:7ad0be7:emoji/src/github.com/kyokomi/emoji \
		magiconair:properties:b3b15ef:properties/src/github.com/magiconair/properties \
		miekg:mmark:2d4f1dd:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:db1efb5:mapstructure/src/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:2c24b78:go_i18n/src/github.com/nicksnyder/go-i18n \
		pelletier:go-buffruneio:c37440a:go_buffruneio/src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:13d49d4:go_toml/src/github.com/pelletier/go-toml \
		russross:blackfriday:5f33e7b:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:9be6508:afero/src/github.com/spf13/afero \
		spf13:cast:ce135a4:cast/src/github.com/spf13/cast \
		spf13:cobra:fcd0c5a:cobra/src/github.com/spf13/cobra \
		spf13:fsync:cb2da33:fsync/src/github.com/spf13/fsync \
		spf13:hugo:d0e2a1f:hugo/src/github.com/spf13/hugo \
		spf13:jWalterWeatherman:fa7ca7e:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:9ff6c69:pflag/src/github.com/spf13/pflag \
		spf13:viper:7538d73:viper/src/github.com/spf13/viper \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		golang:net:d379faa:net/src/golang.org/x/net \
		golang:sys:e48874b:sys/src/golang.org/x/sys \
		golang:text:f28f367:text/src/golang.org/x/text \
		go-yaml:yaml:a3f3340:yaml/src/gopkg.in/yaml.v2

OPTIONS_DEFINE=	MANPAGES
MANPAGES_DESC=	Build and/or install manual pages

OPTIONS_SUB=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES

STRIP=		# stripping can break go binaries

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-build-MANPAGES-on:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ./bin/${PORTNAME} gen man --dir man/man1/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

do-install-MANPAGES-on:
.for i in hugo-benchmark.1 \
		hugo-config.1 \
		hugo-convert-toJSON.1 \
		hugo-convert-toTOML.1 \
		hugo-convert-toYAML.1 \
		hugo-convert.1 \
		hugo-env.1 \
		hugo-gen-autocomplete.1 \
		hugo-gen-doc.1 \
		hugo-gen-man.1 \
		hugo-gen.1 \
		hugo-import-jekyll.1 \
		hugo-import.1 \
		hugo-list-drafts.1 \
		hugo-list-expired.1 \
		hugo-list-future.1 \
		hugo-list.1 \
		hugo-new-site.1 \
		hugo-new-theme.1 \
		hugo-new.1 \
		hugo-server.1 \
		hugo-undraft.1 \
		hugo-version.1 \
		hugo.1
		${INSTALL_MAN} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
