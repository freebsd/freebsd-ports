# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	kapacitor
PORTVERSION=	1.1.0
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
GH_TUPLE=	bmizerany:pat:c068ca2:pat/src/github.com/bmizerany/pat \
		collectd:go-collectd:9fc824c:go_collectd/src/collectd.org \
		dgryski:go-bits:2ad8d70:go_bits/src/github.com/dgryski/go-bits \
		dgryski:go-bitstream:7d46cd2:go_bitstream/src/github.com/dgryski/go-bitstream \
		dominikh:go-js-dom:24aa052:go_js_dom/src/honnef.co/go/js/dom \
		fsnotify:fsnotify:fd9ec7d:fsnotify/src/github.com/fsnotify/fsnotify \
		go-pipe:pipe:3c2ca4d:pipe/src/gopkg.in/pipe.v2 \
		golang:crypto:c197bcf:crypto/src/golang.org/x/crypto \
		golang:net:6acef71:net/src/golang.org/x/net \
		golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
		golang:tools:fc2b74b:tools/src/golang.org/x/tools \
		golang:sys:b699b70:sys/src/golang.org/x/sys \
		gopherjs:gopherjs:e34a5cd:gopherjs/src/github.com/gopherjs/gopherjs \
		jwilder:encoding:4dada27:encoding/src/github.com/jwilder/encoding \
		kardianos:osext:c2c54e5:osext/src/github.com/kardianos/osext \
		microcosm-cc:bluemonday:f77f16f:bluemonday/src/github.com/microcosm-cc/bluemonday \
		neelance:sourcemap:8c68805:sourcemap/src/github.com/neelance/sourcemap \
		paulbellamy:ratecounter:5a11f58:ratecounter/src/github.com/paulbellamy/ratecounter \
		peterh:liner:8975875:liner/src/github.com/peterh/liner \
		rakyll:statik:274df12:statik/src/github.com/rakyll/statik \
		retailnext:hllpp:38a7bb7:hllpp/src/github.com/retailnext/hllpp \
		russross:blackfriday:5f33e7b:blackfriday/src/github.com/russross/blackfriday \
		sergi:go-diff:552b4e9:go_diff/src/github.com/sergi/go-diff \
		shurcooL:github_flavored_markdown:7bcab91:github_flavored_markdown/src/github.com/shurcooL/github_flavored_markdown \
		shurcooL:gopherjslib:feb6d39:gopherjslib/src/github.com/shurcooL/gopherjslib \
		shurcooL:highlight_diff:d3b292e:highlight_diff/src/github.com/shurcooL/highlight_diff \
		shurcooL:highlight_go:7867c2d:highlight_go/src/github.com/shurcooL/highlight_go \
		shurcooL:httpfs:01ca90b:httpfs/src/github.com/shurcooL/httpfs \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized_anchor_name/src/github.com/shurcooL/sanitized_anchor_name \
		sourcegraph:annotate:f4cad6c:annotate/src/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:c95ac47:syntaxhighlight/src/github.com/sourcegraph/syntaxhighlight \
		stretchr:testify:18a02ba:testify/src/github.com/stretchr/testify
# This should work, but go gets confused with the symlinks.
#GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

SUB_FILES=	kapacitord
SUB_LIST+=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}
PLIST_SUB=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@cd ${WRKSRC} && ${MV} \
	LICENSE alert.go auth batch.go build.py build.sh circle-test.sh circle.yml client clock cmd \
	combine.go combine_test.go default.go delete.go derivative.go doc.go edge.go edge_test.go \
	etc eval.go examples expr.go expvar flatten.go global_stats.go gobuild.sh group_by.go \
	http_out.go influxdb influxdb_out.go influxql.gen.go influxql.gen.go.tmpl influxql.go \
	integrations join.go k8s_autoscale.go list-deps log.go metaclient.go models node.go noop.go \
	output.go pipeline query.go query_test.go replay.go result.go sample.go scripts server \
	services shift.go stats.go stream.go task.go task_master.go template.go test.sh tick \
	tickdoc.conf timer tmpldata udf udf.go udf_test.go union.go update_tick_docs.sh usr vendor \
	vendor.list vendor.sh where.go window.go window_test.go \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} \
		&& ${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}d ${STAGEDIR}${PREFIX}/bin/${PORTNAME}d
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
