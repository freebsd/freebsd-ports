# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	kapacitor
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Time-series data collection

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.6.0:lang/go

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

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
	alert alert.go auth batch.go BLOB_STORE_DESIGN.md bufpool build.py \
	build.sh CHANGELOG.md circle-test.sh circle.yml client clock cmd \
	combine_test.go combine.go command CONTRIBUTING.md default.go delete.go \
	derivative.go DESIGN.md doc.go Dockerfile_build_ubuntu32 \
	Dockerfile_build_ubuntu64 Dockerfile_build_ubuntu64_git edge_test.go \
	edge.go etc eval.go examples expr.go expvar flatten.go gobuild.sh \
	group_by.go http_out.go influxdb influxdb_out.go influxql.gen.go \
	influxql.gen.go.tmpl influxql.go integrations join.go k8s_autoscale.go \
	LICENSE LICENSE_OF_DEPENDENCIES.md list-deps log.go metaclient.go \
	models node.go noop.go output.go pipeline query_test.go query.go \
	README.md replay.go result.go sample.go scripts server services \
	shift.go stats.go stream.go task_master.go task.go template.go \
	test.sh tick tickdoc.conf timer tmpldata udf udf_test.go udf.go \
	union.go update_tick_docs.sh usr vars vendor vendor.list vendor.sh \
	where.go window_test.go window.go \
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
