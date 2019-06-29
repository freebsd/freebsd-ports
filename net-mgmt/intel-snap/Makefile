# Created by: Brad Davis <brd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intel-snap
PORTVERSION=	0.0.1
CATEGORIES=	net-mgmt

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Intels open telemetry framework

#LICENSE=	APACHE2

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	stdale
GH_PROJECT=	snap-freebsd
GH_TAGNAME=	ca8016d

GH_TUPLE=	Sirupsen:logrus:61e43dc:logrus/src/github.com/Sirupsen/logrus \
		vrischmann:jsonutil:d44b59f:jsonutil/src/github.com/vrischmann/jsonutil \
		golang:crypto:f18420e:crypto/src/golang.org/x/crypto \
		appc:spec:e99880c:schema/src/github.com/appc/spec \
		asaskevich:govalidator:fdf1978:govalidator/src/github.com/asaskevich/govalidator \
		coreos:go-semver:9474efc:semver/src/github.com/coreos/go-semver \
		ghodss:yaml:04f3134:yaml/src/github.com/ghodss/yaml \
		golang:protobuf:8ee7999:protobuf/src/github.com/golang/protobuf \
		hashicorp:go-msgpack:fa3f638:msgpack/src/github.com/hashicorp/go-msgpack \
		hashicorp:memberlist:9888dc5:memberlist/src/github.com/hashicorp/memberlist \
		armon:go-metrics:06b6099:metrics/src/github.com/armon/go-metrics \
		intelsdi-x:gomit:db68f6f:gomit/src/github.com/intelsdi-x/gomit \
		julienschmidt:httprouter:8a45e95:httprouter/src/github.com/julienschmidt/httprouter \
		robfig:cron:9585fd5:cron/src/github.com/robfig/cron \
		urfave:cli:347a988:cli2/src/github.com/urfave/cli \
		urfave:negroni:61dbefc:negroni/src/github.com/urfave/negroni \
		pborman:uuid:1b00554:uuid/src/github.com/pborman/uuid \
		spf13:pflag:9ff6c69:pflag/src/github.com/spf13/pflag \
		xeipuuv:gojsonschema:f06f290:gojsonschema/src/github.com/xeipuuv/gojsonschema \
		xeipuuv:gojsonreference:e02fc20:gojsonreference/src/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonpointer:e0fe6f6:gojsonpointer/src/github.com/xeipuuv/gojsonpointer \
		golang:net:41bba8d:net/src/golang.org/x/net \
		abh:errorutil:f9bd360:errorutil/src/go4.org/errorutil \
		go-yaml:yaml:4c78c97:yaml2/src/gopkg.in/yaml.v2 \
		go-inf:inf:3887ee9:inf/src/gopkg.in/inf.v0 \
		grpc:grpc-go:b1efb1e:grpc/src/google.golang.org/grpc \
		ghodss:yaml:04f3134:yaml/src/github.com/ghodss/yaml

PLIST_FILES=	bin/snapctl bin/snapd

do-build:
	( cd ${WRKSRC}; ${LN} -s ${WRKSRC} ${WRKSRC}/src/github.com/intelsdi-x/snap )
	( cd ${WRKSRC}/src/github.com/appc/spec; \
		${SETENV} ${BUILD_ENV} ${MAKE_ENV} GOPATH=${WRKSRC} CC=clang \
		go build -o bin/actool github.com/appc/spec/actool )
	( cd ${WRKSRC}; \
		${SETENV} ${BUILD_ENV} ${MAKE_ENV} GOPATH=${WRKSRC} CC=clang \
		go build ${BUILD_FLAGS} -o bin/snapd )
	( cd ${WRKSRC}/cmd/snapctl; \
		${SETENV} ${BUILD_ENV} ${MAKE_ENV} GOPATH=${WRKSRC} CC=clang \
		go build ${BUILD_FLAGS} -o bin/snapctl )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/snapctl/bin/snapctl ${STAGEDIR}${PREFIX}/bin/snapctl
	${INSTALL_PROGRAM} ${WRKSRC}/bin/snapd ${STAGEDIR}${PREFIX}/bin/snapd

.include <bsd.port.mk>
