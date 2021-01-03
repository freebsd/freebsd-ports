# $FreeBSD$

PORTNAME=	assh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Smart SSH client wrapper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	moul
GH_TUPLE=	Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		awalterschulze:gographviz:v2.0.1:awalterschulze_gographviz/vendor/github.com/awalterschulze/gographviz \
		bugsnag:osext:0dd3f918b21b:bugsnag_osext/vendor/github.com/bugsnag/osext \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		deckarep:gosx-notifier:e127226297fb:deckarep_gosx_notifier/vendor/github.com/deckarep/gosx-notifier \
		moby:moby:v1.13.1:docker_docker/vendor/github.com/docker/docker \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libcompose:v0.4.0:docker_libcompose/vendor/github.com/docker/libcompose \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.6.3:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.3.0:go_playground_validator/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:70a84ac30bf9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:6fdc65e7d980:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:89c76fbcd5d1:golang_time/vendor/golang.org/x/time \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gopherjs:gopherjs:0766667cb4d1:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		guelfey:go.dbus:f6a3a2366cc3:guelfey_go_dbus/vendor/github.com/guelfey/go.dbus \
		haklop:gnotifier:0de36badf601:haklop_gnotifier/vendor/github.com/haklop/gnotifier \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		jtolds:gls:v4.20.0:jtolds_gls/vendor/github.com/jtolds/gls \
		leodido:go-urn:v1.2.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-zglob:v0.0.2:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.3.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		moul:flexyaml:f458bfa8afe2:moul_flexyaml/vendor/github.com/moul/flexyaml \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shirou:gopsutil:v2.20.5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.15.0:uber_go_zap/vendor/go.uber.org/zap \
		ugorji:go:v1.1.7:ugorji_go/vendor/github.com/ugorji/go/codec \
		urfave:cli:v1.22.4:urfave_cli/vendor/github.com/urfave/cli \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

PLIST_FILES=	bin/assh

post-patch:
	${REINPLACE_CMD} -e '/Version/s,n/a,${DISTVERSION},' \
		-e '/VcsRef/s,n/a,${DISTVERSIONPREFIX}${DISTVERSION},' \
		${WRKSRC}/pkg/version/version.go

.include <bsd.port.mk>
