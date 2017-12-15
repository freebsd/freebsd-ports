# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	kapacitor
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Time-series data collection

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go>=1.6.0:lang/go

USE_RC_SUBR=	kapacitord

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata:DEFAULT

# This should work, but go gets confused with the symlinks.
#GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

SUB_FILES=	kapacitord
SUB_LIST+=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}
PLIST_SUB=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@cd ${WRKSRC} && ${MV} \
	BLOB_STORE_DESIGN.md CHANGELOG.md CONTRIBUTING.md DESIGN.md \
	Gopkg.lock Gopkg.toml LICENSE_OF_DEPENDENCIES.md README.md \
	alert alert.go auth batch.go bufpool build.py build.sh \
	circle-test.sh circle.yml client clock cmd combine.go combine_test.go \
	command default.go delete.go derivative.go doc.go edge.go \
	edge_test.go etc eval.go examples expr.go expvar flatten.go \
	gobuild.sh group_by.go http_out.go http_post.go influxdb \
	influxdb_out.go influxql.gen.go influxql.gen.go.tmpl influxql.go \
	integrations join.go k8s_autoscale.go kapacitor_loopback.go \
	list-deps listmap log.go metaclient.go models node.go noop.go \
	output.go pipeline query.go query_test.go replay.go result.go \
	sample.go scripts server services shift.go state_tracking.go \
	stats.go stream.go task.go task_master.go template.go test.sh \
	tick tickdoc.conf timer tmpldata.json udf udf.go udf_test.go \
	union.go update_tick_docs.sh usr uuid vars vendor where.go \
	window.go window_test.go \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} \
		&& ${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/${PORTNAME} \
		&& ${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/${PORTNAME}d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}d ${STAGEDIR}${PREFIX}/bin/${PORTNAME}d
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
