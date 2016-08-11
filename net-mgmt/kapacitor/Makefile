# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	kapacitor
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Time-series data collection

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	i386 amd64 armv6

USE_RC_SUBR=	kapacitord

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	golang:crypto:b6789ab:crypto \
		stretchr:testify:6cb3b85:testify

SUB_FILES=	kapacitord
SUB_LIST+=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}
PLIST_SUB=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME} \
	${WRKSRC}/src/github.com/stretchr \
	${WRKSRC}/src/golang.org/x
	@cd ${WRKSRC} && ${MV} CHANGELOG.md CONTRIBUTING.md DESIGN.md Dockerfile_build_ubuntu32 \
	Dockerfile_build_ubuntu64 Dockerfile_build_ubuntu64_git LICENSE LICENSE_OF_DEPENDENCIES.md \
	README.md alert.go batch.go build.py build.sh circle-test.sh circle.yml client clock cmd \
	default.go derivative.go doc.go edge.go edge_test.go etc eval.go examples expr.go expvar \
	global_stats.go gobuild.sh group_by.go http_out.go influxdb_out.go influxql.gen.go \
	influxql.gen.go.tmpl influxql.go install-deps.sh integrations join.go log.go models \
	node.go noop.go output.go pipeline query.go replay.go result.go sample.go scripts services \
	shift.go stats.go stream.go task.go task_master.go test.sh tick tickdoc.conf timer \
	tmpldata udf udf.go udf_test.go union.go update_tick_docs.sh vendor vendor.yml where.go \
	window.go window_test.go \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${MV} ${WRKSRC_testify} ${WRKSRC}/src/github.com/stretchr/testify ;\
	${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} && ${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}d ${STAGEDIR}${PREFIX}/bin/${PORTNAME}d
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
