# $FreeBSD$

PORTNAME=		carbonzipper
DISTVERSION=		0.74
CATEGORIES=		net-mgmt

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Proxy between carbonapi and go-carbon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		go>=1.8:lang/go

USES=			go

USE_GITHUB=		yes
GH_ACCOUNT=		go-graphite
GH_SUBDIR=		src/github.com/go-graphite/${PORTNAME}
GH_TUPLE=		bradfitz:gomemcache:1952afa:gomemcache/src/github.com/bradfitz/gomemcache \
			dgryski:httputil:189c2918:httputil/src/github.com/dgryski/httputil \
			dgryski:go-expirecache:743ef98:goexpirecache/src/github.com/dgryski/go-expirecache \
			facebookgo:atomicfile:2de1f20:atomicfile/src/github.com/facebookgo/atomicfile \
			facebookgo:clock:600d898:clock/src/github.com/facebookgo/clock \
			facebookgo:grace:4afe952:grace/src/github.com/facebookgo/grace \
			facebookgo:httpdown:a3b1354:httpdown/src/github.com/facebookgo/httpdown \
			facebookgo:pidfile:f242e299:pidfile/src/github.com/facebookgo/pidfile \
			facebookgo:stats:1b76add:stats/src/github.com/facebookgo/stats \
			gogo:protobuf:v0.4:protobuf/src/github.com/gogo/protobuf \
			go-yaml:yaml:v2.1.1:yaml/src/gopkg.in/yaml.v2 \
			lestrrat:go-strftime:04ef93e:gostrftime/src/github.com/lestrrat/go-strftime \
			lestrrat-go:file-rotatelogs:v2.1.0:filerotatelogs/src/github.com/lestrrat/go-file-rotatelogs \
			lomik:og-rek:628eefe:ogrek/src/github.com/lomik/og-rek \
			lomik:zapwriter:d4499a3:zapwriter/src/github.com/lomik/zapwriter \
		        peterbourgon:g2g:0c2bab2:g2g/src/github.com/peterbourgon/g2g \
			pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
			satori:go.uuid:v1.1.0:gouuid/src/github.com/satori/go.uuid \
			uber-go:atomic:v1.2.0:atomic/src/go.uber.org/atomic \
			uber-go:multierr:v1.1.0:multierr/src/go.uber.org/multierr \
			uber-go:zap:v1.5.0:zap/src/go.uber.org/zap

USE_RC_SUBR=		${PORTNAME}

USERS=			carbon
GROUPS=			carbon

do-build:
	@cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} \
		go build --ldflags '-X main.BuildVersion=${DISTVERSION}' -o carbonzipper

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/carbonzipper
	@${MKDIR} ${STAGEDIR}/var/log/carbonzipper
	${INSTALL_PROGRAM} ${WRKSRC}/carbonzipper ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.conf ${STAGEDIR}${PREFIX}/etc/carbonzipper

.include <bsd.port.mk>
