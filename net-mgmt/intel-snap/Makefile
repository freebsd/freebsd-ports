# Created by: Brad Davis <brd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intel-snap
PORTVERSION=	0.0.1
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intels open telemetry framework

#LICENSE=	APACHE2

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	stdale
GH_PROJECT=	snap-freebsd
GH_TAGNAME=	ca8016d

GH_TUPLE=	Sirupsen:logrus:61e43dc:logrus/vendor/github.com/Sirupsen/logrus \
		vrischmann:jsonutil:d44b59f:jsonutil/vendor/github.com/vrischmann/jsonutil \
		golang:crypto:f18420e:crypto/vendor/golang.org/x/crypto \
		appc:spec:e99880c:schema/vendor/github.com/appc/spec \
		asaskevich:govalidator:fdf1978:govalidator/vendor/github.com/asaskevich/govalidator \
		coreos:go-semver:9474efc:semver/vendor/github.com/coreos/go-semver \
		ghodss:yaml:04f3134:yaml/vendor/github.com/ghodss/yaml \
		golang:protobuf:8ee7999:protobuf/vendor/github.com/golang/protobuf \
		hashicorp:go-msgpack:fa3f638:msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:memberlist:9888dc5:memberlist/vendor/github.com/hashicorp/memberlist \
		armon:go-metrics:06b6099:metrics/vendor/github.com/armon/go-metrics \
		intelsdi-x:gomit:db68f6f:gomit/vendor/github.com/intelsdi-x/gomit \
		julienschmidt:httprouter:8a45e95:httprouter/vendor/github.com/julienschmidt/httprouter \
		robfig:cron:9585fd5:cron/vendor/github.com/robfig/cron \
		urfave:cli:347a988:cli2/vendor/github.com/urfave/cli \
		urfave:negroni:61dbefc:negroni/vendor/github.com/urfave/negroni \
		pborman:uuid:1b00554:uuid/vendor/github.com/pborman/uuid \
		spf13:pflag:9ff6c69:pflag/vendor/github.com/spf13/pflag \
		xeipuuv:gojsonschema:f06f290:gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		xeipuuv:gojsonreference:e02fc20:gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonpointer:e0fe6f6:gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		golang:net:41bba8d:net/vendor/golang.org/x/net \
		abh:errorutil:f9bd360:errorutil/vendor/go4.org/errorutil \
		go-yaml:yaml:4c78c97:yaml2/vendor/gopkg.in/yaml.v2 \
		go-inf:inf:3887ee9:inf/vendor/gopkg.in/inf.v0 \
		grpc:grpc-go:b1efb1e:grpc/vendor/google.golang.org/grpc \
		ghodss:yaml:04f3134:yaml/vendor/github.com/ghodss/yaml

GO_PKGNAME=	github.com/intelsdi-x/snap
GO_TARGET=	.:snapd \
		./cmd/snapctl

PLIST_FILES=	bin/snapctl bin/snapd

.include <bsd.port.mk>
