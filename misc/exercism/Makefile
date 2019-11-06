# $FreeBSD$

PORTNAME=	exercism
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.11
CATEGORIES=	misc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_TUPLE=	\
		exercism:cli:v${PORTVERSION}:DEFAULT \
		armon:consul-api:eb2c6b5:consulapi/vendor/github.com/armon/consul-api \
		blang:semver:v3.5.1:semver/vendor/github.com/blang/semver \
		coreos:etcd:v0.2.0:etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.2.0:gosemver/vendor/github.com/coreos/go-semver \
		cpuguy83:go-md2man:v1.0.8:md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.0:gospew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.2:fsnotify/vendor/github.com/fsnotify/fsnotify \
		hashicorp:hcl:392dba7:hcl/vendor/github.com/hashicorp/hcl \
		golang:protobuf:v1.2.0:protobuf/vendor/github.com/golang/protobuf \
		inconshreveable:go-update:8152e7e:goupdate/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0:mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kr:fs:v0.1.0:fs/vendor/github.com/kr/fs \
		kr:pretty:v0.1.0:pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:text/vendor/github.com/kr/text \
		magiconair:properties:v1.7.3:properties/vendor/github.com/magiconair/properties \
		mitchellh:go-homedir:v1.0.0:gohomedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:d0303fe:mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:v0.2.0:gobuffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.0.0:gotoml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.8.3:sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:godifflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v1.5.1:blackfriday/vendor/github.com/russross/blackfriday \
		spf13:afero:9be6508:afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.1.0:cast/vendor/github.com/spf13/cast \
		spf13:cobra:b26b538:cobra/vendor/github.com/spf13/cobra \
		spf13:jWalterWeatherman:0efa520:jww/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:e57e3ee:pflag/vendor/github.com/spf13/pflag \
		spf13:viper:1573881:viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.1.1:objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.1.4:testify/vendor/github.com/stretchr/testify \
		ugorji:go:v1.1.1:ugorji/vendor/github.com/ugorji/go \
		xordataexchange:crypt:b2862e3:dataexchange/vendor/github.com/xordataexchange/crypt \
		golang:crypto:0e37d00:crypto/vendor/golang.org/x/crypto \
		golang:net:f5079bd:net/vendor/golang.org/x/net \
		golang:oauth2:d2e6202:oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:d8f5ea2:sys/vendor/golang.org/x/sys \
		golang:text:3bd178b:text/vendor/golang.org/x/text \
		golang:tools:90fa682:tour/vendor/golang.org/x/tools \
		golang:appengine:ae0ab99:appengine/vendor/google.golang.org/appengine \
		googleapis:google-api-go-client:920bb1b:gapis/vendor/google.golang.org/api \
		GoogleCloudPlatform:google-cloud-go:v0.28.0:gcloudgo/vendor/cloud.google.com/go \
		go4org:go4:417644f:go4/vendor/go4.org \
		go-check:check:788fd78:gocheck/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:25c4ec8:yaml/vendor/gopkg.in/yaml.v2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./exercism
GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X github.com/exercism/cli/cmd.BuildOS=freebsd \
		-X github.com/exercism/cli/cmd.BuildARCH=${ARCH}"

PLIST_FILES=	bin/exercism

.include <bsd.port.mk>
