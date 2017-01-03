# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	0.18.1
PORTREVISION=	1
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
GH_TUPLE=	eknkc:amber:9be5e8a:amber/src/github.com/eknkc/amber \
		spf13:afero:90dd71e:afero/src/github.com/spf13/afero \
		spf13:jWalterWeatherman:33c24e7:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:cast:56a7ecb:cast/src/github.com/spf13/cast \
		spf13:cobra:1dd5ff2:cobra/src/github.com/spf13/cobra \
		spf13:fsync:cb2da33:fsync/src/github.com/spf13/fsync \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:25f8b5b:pflag/src/github.com/spf13/pflag \
		spf13:viper:5ed0fc3:viper/src/github.com/spf13/viper \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		BurntSushi:toml:9906417:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:0bcb03f:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:5bd2802:urlesc/src/github.com/PuerkitoBio/urlesc \
		bep:inflect:b896c45:inflect/src/github.com/bep/inflect \
		dchest:cssmin:fb8d9b4:cssmin/src/github.com/dchest/cssmin \
		fsnotify:fsnotify:fd9ec7d:fsnotify/src/github.com/fsnotify/fsnotify \
		gorilla:websocket:5ddbd28:websocket/src/github.com/gorilla/websocket \
		hashicorp:hcl:80e628d:hcl/src/github.com/hashicorp/hcl \
		kardianos:osext:c2c54e5:osext/src/github.com/kardianos/osext \
		kyokomi:emoji:7e06b23:emoji/src/github.com/kyokomi/emoji \
		magiconair:properties:9c47895:properties/src/github.com/magiconair/properties \
		miekg:mmark:2d4f1dd:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:bfdb1a8:mapstructure/src/github.com/mitchellh/mapstructure \
		russross:blackfriday:5f33e7b:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		golang:sys:d75a526:sys/src/golang.org/x/sys \
		golang:text:fd889fe:text/src/golang.org/x/text \
		golang:net:f4b625e:net/src/golang.org/x/net \
		go-yaml:yaml:a5b47d3:yaml/src/gopkg.in/yaml.v2 \
		cpuguy83:go-md2man:a65d4d2:go_md2man/src/github.com/cpuguy83/go-md2man \
		nicksnyder:go-i18n:e6c90c3:go_i18n/src/github.com/nicksnyder/go-i18n \
		pelletier:go-toml:64ff1ea:go_toml/src/github.com/pelletier/go-toml \
		pelletier:go-buffruneio:df1e16f:go_buffruneio/src/github.com/pelletier/go-buffruneio \
		bep:gitmap:a1a71ab:gitmap/src/github.com/bep/gitmap \
		fortytw2:leaktest:0db74e8:leaktest/src/github.com/fortytw2/leaktest

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
