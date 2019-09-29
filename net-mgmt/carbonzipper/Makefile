# $FreeBSD$

PORTNAME=		carbonzipper
DISTVERSION=		0.74
CATEGORIES=		net-mgmt

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Proxy between carbonapi and go-carbon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			go

USE_GITHUB=		yes
GH_ACCOUNT=		go-graphite
GH_SUBDIR=		src/github.com/go-graphite/${PORTNAME}
GH_TUPLE=		bradfitz:gomemcache:1952afa:gomemcache/vendor/github.com/bradfitz/gomemcache \
			dgryski:httputil:189c2918:httputil/vendor/github.com/dgryski/httputil \
			dgryski:go-expirecache:743ef98:goexpirecache/vendor/github.com/dgryski/go-expirecache \
			facebookgo:atomicfile:2de1f20:atomicfile/vendor/github.com/facebookgo/atomicfile \
			facebookgo:clock:600d898:clock/vendor/github.com/facebookgo/clock \
			facebookgo:grace:4afe952:grace/vendor/github.com/facebookgo/grace \
			facebookgo:httpdown:a3b1354:httpdown/vendor/github.com/facebookgo/httpdown \
			facebookgo:pidfile:f242e299:pidfile/vendor/github.com/facebookgo/pidfile \
			facebookgo:stats:1b76add:stats/vendor/github.com/facebookgo/stats \
			gogo:protobuf:v0.4:protobuf/vendor/github.com/gogo/protobuf \
			go-yaml:yaml:v2.1.1:yaml/vendor/gopkg.in/yaml.v2 \
			lestrrat:go-strftime:04ef93e:gostrftime/vendor/github.com/lestrrat/go-strftime \
			lestrrat-go:file-rotatelogs:v2.1.0:filerotatelogs/vendor/github.com/lestrrat/go-file-rotatelogs \
			lomik:og-rek:628eefe:ogrek/vendor/github.com/lomik/og-rek \
			lomik:zapwriter:d4499a3:zapwriter/vendor/github.com/lomik/zapwriter \
		        peterbourgon:g2g:0c2bab2:g2g/vendor/github.com/peterbourgon/g2g \
			pkg:errors:v0.8.0:errors/vendor/github.com/pkg/errors \
			satori:go.uuid:v1.1.0:gouuid/vendor/github.com/satori/go.uuid \
			uber-go:atomic:v1.2.0:atomic/vendor/go.uber.org/atomic \
			uber-go:multierr:v1.1.0:multierr/vendor/go.uber.org/multierr \
			uber-go:zap:v1.5.0:zap/vendor/go.uber.org/zap

GO_BUILDFLAGS=		-ldflags='-X main.BuildVersion=${DISTVERSION}'

USE_RC_SUBR=		${PORTNAME}

USERS=			carbon
GROUPS=			carbon

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/carbonzipper
	@${MKDIR} ${STAGEDIR}/var/log/carbonzipper
	${INSTALL_DATA} ${WRKSRC}/example.conf ${STAGEDIR}${PREFIX}/etc/carbonzipper

.include <bsd.port.mk>
