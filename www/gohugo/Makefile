# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	0.16
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and modern static website engine

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.5.0:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	eknkc:amber \
		spf13:DEFAULT,afero,jWalterWeatherman,cast,cobra \
		spf13:fsync,nitro,pflag,viper \
		yosssi:ace \
		BurntSushi:toml \
		PuerkitoBio:purell,urlesc \
		bep:inflect \
		dchest:cssmin \
		fsnotify:fsnotify \
		gorilla:websocket \
		hashicorp:hcl \
		kardianos:osext \
		kr:fs \
		kyokomi:emoji \
		magiconair:properties \
		miekg:mmark \
		mitchellh:mapstructure \
		pkg:errors,sftp \
		russross:blackfriday \
		shurcooL:sanitized_anchor_name \
		golang:crypto,sys,text \
		go-yaml:yaml \
		cpuguy83:go_md2man
GH_PROJECT=	amber:amber afero:afero \
		jWalterWeatherman:jWalterWeatherman ace:ace toml:toml \
		purell:purell urlesc:urlesc inflect:inflect cssmin:cssmin \
		fsnotify:fsnotify websocket:websocket hcl:hcl osext:osext \
		fs:fs emoji:emoji properties:properties mmark:mmark \
		mapstructure:mapstructure errors:errors sftp:sftp \
		go-md2man:go_md2man blackfriday:blackfriday \
		sanitized_anchor_name:sanitized_anchor_name cast:cast \
		cobra:cobra fsync:fsync nitro:nitro pflag:pflag viper:viper \
		crypto:crypto sys:sys text:text yaml:yaml
GH_TAGNAME=	91774f0:amber 9d16de2:afero \
		33c24e7:jWalterWeatherman 71afeb7:ace bec2dac:toml \
		1d5d1cf:purell 5fa9ff0:urlesc b896c45:inflect \
		2724a9c:go_md2man fb8d9b4:cssmin a8a77c9:fsnotify \
		a836c37:websocket d8c773c:hcl 29ae4ff:osext 2788f0d:fs \
		17c5e70:emoji e2f061e:properties adb5c3e:mmark \
		d2dd026:mapstructure a2d6902:errors 57fcf4a:sftp \
		1d6b8e9:blackfriday 10ef21a:sanitized_anchor_name 27b586b:cast \
		a272c3c:cobra 1773df7:fsync 24d7ef3:nitro 3678644:pflag \
		c1ccc37:viper 2c99acd:crypto a408501:sys d5d7737:text \
		a83829b:yaml

STRIP=		# stripping can break go binaries

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/PuerkitoBio
	@${MKDIR} ${WRKSRC}/src/github.com/bep
	@${MKDIR} ${WRKSRC}/src/github.com/cpuguy83
	@${MKDIR} ${WRKSRC}/src/github.com/dchest
	@${MKDIR} ${WRKSRC}/src/github.com/eknkc
	@${MKDIR} ${WRKSRC}/src/github.com/fsnotify
	@${MKDIR} ${WRKSRC}/src/github.com/gorilla
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/kardianos
	@${MKDIR} ${WRKSRC}/src/github.com/kr
	@${MKDIR} ${WRKSRC}/src/github.com/kyokomi
	@${MKDIR} ${WRKSRC}/src/github.com/magiconair
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/pkg
	@${MKDIR} ${WRKSRC}/src/github.com/russross
	@${MKDIR} ${WRKSRC}/src/github.com/shurcooL
	@${MKDIR} ${WRKSRC}/src/github.com/spf13
	@${MKDIR} ${WRKSRC}/src/github.com/spf13/hugo
	@${MKDIR} ${WRKSRC}/src/github.com/yosssi
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in
.for src in CONTRIBUTING.md Dockerfile LICENSE.md Makefile README.md bench.sh \
		bufferpool commands create docs examples helpers hugofs \
		hugolib livereload main.go parser requirements.txt source \
		target tpl transform utils watcher wercker.yml
		@${MV} ${WRKSRC}/${src} \
			${WRKSRC}/src/github.com/spf13/${PORTNAME}
.endfor
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_purell} ${WRKSRC}/src/github.com/PuerkitoBio/purell
	@${MV} ${WRKSRC_urlesc} ${WRKSRC}/src/github.com/PuerkitoBio/urlesc
	@${MV} ${WRKSRC_inflect} ${WRKSRC}/src/github.com/bep/inflect
	@${MV} ${WRKSRC_go_md2man} ${WRKSRC}/src/github.com/cpuguy83/go-md2man
	@${MV} ${WRKSRC_cssmin} ${WRKSRC}/src/github.com/dchest/cssmin
	@${MV} ${WRKSRC_amber} ${WRKSRC}/src/github.com/eknkc/amber
	@${MV} ${WRKSRC_fsnotify} ${WRKSRC}/src/github.com/fsnotify/fsnotify
	@${MV} ${WRKSRC_websocket} ${WRKSRC}/src/github.com/gorilla/websocket
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/kardianos/osext
	@${MV} ${WRKSRC_fs} ${WRKSRC}/src/github.com/kr/fs
	@${MV} ${WRKSRC_emoji} ${WRKSRC}/src/github.com/kyokomi/emoji
	@${MV} ${WRKSRC_properties} ${WRKSRC}/src/github.com/magiconair/properties
	@${MV} ${WRKSRC_mmark} ${WRKSRC}/src/github.com/miekg/mmark
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_errors} ${WRKSRC}/src/github.com/pkg/errors
	@${MV} ${WRKSRC_sftp} ${WRKSRC}/src/github.com/pkg/sftp
	@${MV} ${WRKSRC_blackfriday} ${WRKSRC}/src/github.com/russross/blackfriday
	@${MV} ${WRKSRC_sanitized_anchor_name} ${WRKSRC}/src/github.com/shurcooL/sanitized_anchor_name
	@${MV} ${WRKSRC_afero} ${WRKSRC}/src/github.com/spf13/afero
	@${MV} ${WRKSRC_cast} ${WRKSRC}/src/github.com/spf13/cast
	@${MV} ${WRKSRC_cobra} ${WRKSRC}/src/github.com/spf13/cobra
	@${MV} ${WRKSRC_fsync} ${WRKSRC}/src/github.com/spf13/fsync
	@${MV} ${WRKSRC_jWalterWeatherman} ${WRKSRC}/src/github.com/spf13/jwalterweatherman
	@${MV} ${WRKSRC_nitro} ${WRKSRC}/src/github.com/spf13/nitro
	@${MV} ${WRKSRC_pflag} ${WRKSRC}/src/github.com/spf13/pflag
	@${MV} ${WRKSRC_viper} ${WRKSRC}/src/github.com/spf13/viper
	@${MV} ${WRKSRC_ace} ${WRKSRC}/src/github.com/yosssi/ace
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_sys} ${WRKSRC}/src/golang.org/x/sys
	@${MV} ${WRKSRC_text} ${WRKSRC}/src/golang.org/x/text
	@${MV} ${WRKSRC_yaml} ${WRKSRC}/src/gopkg.in/yaml.v2

do-build:
	@cd ${WRKSRC}/src/github.com/spf13/${PORTNAME} && ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
	@cd ${WRKSRC}/src/github.com/spf13/${PORTNAME} && ./bin/${PORTNAME} gen man --dir man/man1/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/spf13/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
.for i in hugo.1 hugo_benchmark.1 hugo_check.1 hugo_config.1 hugo_convert.1 \
		hugo_convert_toJSON.1 hugo_convert_toTOML.1 \
		hugo_convert_toYAML.1 hugo_gen.1 hugo_gen_autocomplete.1 \
		hugo_gen_doc.1 hugo_gen_man.1 hugo_import.1 \
		hugo_import_jekyll.1 hugo_list.1 hugo_list_drafts.1 \
		hugo_list_future.1 hugo_new.1 hugo_new_site.1 hugo_new_theme.1 \
		hugo_server.1 hugo_undraft.1 hugo_version.1
		${INSTALL_MAN} ${WRKSRC}/src/github.com/spf13/${PORTNAME}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
