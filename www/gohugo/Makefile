# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	0.17
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
GH_TUPLE=	eknkc:amber:80f9e27:amber/src/github.com/eknkc/amber \
		spf13:afero:52e4a6c:afero/src/github.com/spf13/afero \
		spf13:jWalterWeatherman:33c24e7:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		spf13:cast:2580bc9:cast/src/github.com/spf13/cast \
		spf13:cobra:9c28e4b:cobra/src/github.com/spf13/cobra \
		spf13:fsync:1773df7:fsync/src/github.com/spf13/fsync \
		spf13:nitro:24d7ef3:nitro/src/github.com/spf13/nitro \
		spf13:pflag:b83537d:pflag/src/github.com/spf13/pflag \
		spf13:viper:ec4eb2f:viper/src/github.com/spf13/viper \
		yosssi:ace:ea038f4:ace/src/github.com/yosssi/ace \
		BurntSushi:toml:bbd5bb6:toml/src/github.com/BurntSushi/toml \
		PuerkitoBio:purell:8a29053:purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:5bd2802:urlesc/src/github.com/PuerkitoBio/urlesc \
		bep:inflect:b896c45:inflect/src/github.com/bep/inflect \
		dchest:cssmin:fb8d9b4:cssmin/src/github.com/dchest/cssmin \
		fsnotify:fsnotify:944cff2:fsnotify/src/github.com/fsnotify/fsnotify \
		gorilla:websocket:1f512fc:websocket/src/github.com/gorilla/websocket \
		hashicorp:hcl:6f5bfed:hcl/src/github.com/hashicorp/hcl \
		kardianos:osext:c2c54e5:osext/src/github.com/kardianos/osext \
		kr:fs:2788f0d:fs/src/github.com/kr/fs \
		kyokomi:emoji:17c5e70:emoji/src/github.com/kyokomi/emoji \
		magiconair:properties:c265cfa:properties/src/github.com/magiconair/properties \
		miekg:mmark:c584d6f:mmark/src/github.com/miekg/mmark \
		mitchellh:mapstructure:a6ef2f0:mapstructure/src/github.com/mitchellh/mapstructure \
		pkg:errors:645ef00:errors/src/github.com/pkg/errors \
		pkg:sftp:4d0e916:sftp/src/github.com/pkg/sftp \
		russross:blackfriday:0b647d0:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		golang:crypto:d172538:crypto/src/golang.org/x/crypto \
		golang:sys:8d1157a:sys/src/golang.org/x/sys \
		golang:text:ede1cb9:text/src/golang.org/x/text \
		golang:net:f4b625e:net/src/golang.org/x/net \
		go-yaml:yaml:a5b47d3:yaml/src/gopkg.in/yaml.v2 \
		cpuguy83:go-md2man:a65d4d2:go_md2man/src/github.com/cpuguy83/go-md2man \
		nicksnyder:go-i18n:e6c90c3:go_i18n/src/github.com/nicksnyder/go-i18n \
		pelletier:go-toml:64ff1ea:go_toml/src/github.com/pelletier/go-toml \
		pelletier:go-buffruneio:df1e16f:go_buffruneio/src/github.com/pelletier/go-buffruneio

STRIP=		# stripping can break go binaries

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ./bin/${PORTNAME} gen man --dir man/man1/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
.for i in hugo.1 hugo_benchmark.1 hugo_check.1 hugo_config.1 hugo_convert.1 \
		hugo_convert_toJSON.1 hugo_convert_toTOML.1 \
		hugo_convert_toYAML.1 hugo_gen.1 hugo_gen_autocomplete.1 \
		hugo_gen_doc.1 hugo_gen_man.1 hugo_import.1 \
		hugo_import_jekyll.1 hugo_list.1 hugo_list_drafts.1 \
		hugo_list_future.1 hugo_new.1 hugo_new_site.1 hugo_new_theme.1 \
		hugo_server.1 hugo_undraft.1 hugo_version.1 hugo_env.1 \
		hugo_list_expired.1
		${INSTALL_MAN} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
