# $FreeBSD$

PORTNAME=	exercism
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.11
CATEGORIES=	misc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes

GH_TUPLE=	\
		exercism:cli:v${PORTVERSION}:DEFAULT/src/github.com/exercism/cli \
		armon:consul-api:eb2c6b5:consulapi/src/github.com/armon/consul-api \
		blang:semver:v3.5.1:semver/src/github.com/blang/semver \
		coreos:etcd:v0.2.0:etcd/src/github.com/coreos/etcd \
		coreos:go-semver:v0.2.0:gosemver/src/github.com/coreos/go-semver \
		cpuguy83:go-md2man:v1.0.8:md2man/src/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.0:gospew/src/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.2:fsnotify/src/github.com/fsnotify/fsnotify \
		hashicorp:hcl:392dba7:hcl/src/github.com/hashicorp/hcl \
		golang:protobuf:v1.2.0:protobuf/src/github.com/golang/protobuf \
		inconshreveable:go-update:8152e7e:goupdate/src/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0:mousetrap/src/github.com/inconshreveable/mousetrap \
		kr:fs:v0.1.0:fs/src/github.com/kr/fs \
		kr:pretty:v0.1.0:pretty/src/github.com/kr/pretty \
		kr:text:v0.1.0:text/src/github.com/kr/text \
		magiconair:properties:v1.7.3:properties/src/github.com/magiconair/properties \
		mitchellh:go-homedir:v1.0.0:gohomedir/src/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:d0303fe:mapstructure/src/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:v0.2.0:gobuffruneio/src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.0.0:gotoml/src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
		pkg:sftp:v1.8.3:sftp/src/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:godifflib/src/github.com/pmezard/go-difflib \
		russross:blackfriday:v1.5.1:blackfriday/src/github.com/russross/blackfriday \
		spf13:afero:9be6508:afero/src/github.com/spf13/afero \
		spf13:cast:v1.1.0:cast/src/github.com/spf13/cast \
		spf13:cobra:b26b538:cobra/src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:0efa520:jww/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		spf13:viper:1573881:viper/src/github.com/spf13/viper \
		stretchr:objx:v0.1.1:objx/src/github.com/stretchr/objx \
		stretchr:testify:v1.1.4:testify/src/github.com/stretchr/testify \
		ugorji:go:v1.1.1:ugorji/src/github.com/ugorji/go \
		xordataexchange:crypt:b2862e3:dataexchange/src/github.com/xordataexchange/crypt \
		golang:crypto:0e37d00:crypto/src/golang.org/x/crypto \
		golang:net:f5079bd:net/src/golang.org/x/net \
		golang:oauth2:d2e6202:oauth2/src/golang.org/x/oauth2 \
		golang:sys:d8f5ea2:sys/src/golang.org/x/sys \
		golang:text:3bd178b:text/src/golang.org/x/text \
		golang:tools:90fa682:tour/src/golang.org/x/tools \
		golang:appengine:ae0ab99:appengine/src/google.golang.org/appengine \
		googleapis:google-api-go-client:920bb1b:gapis/src/google.golang.org/api \
		GoogleCloudPlatform:google-cloud-go:v0.28.0:gcloudgo/src/cloud.google.com/go \
		go4org:go4:417644f:go4/src/go4.org \
		go-check:check:788fd78:gocheck/src/gopkg.in/check.v1 \
		go-yaml:yaml:25c4ec8:yaml/src/gopkg.in/yaml.v2

GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/exercism

do-build:
	@(cd ${WRKSRC} ; \
		${SETENV} ${MAKE_ENV} GO15VENDOREXPERIMENT=1 GOPATH=${WRKSRC} go build -ldflags "-s -w -X github.com/exercism/cli/cmd.BuildOS=freebsd -X github.com/exercism/cli/cmd.BuildARCH=${ARCH}" -o out/exercism exercism/main.go)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/exercism ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
