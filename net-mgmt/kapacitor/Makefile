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
GH_TUPLE=	bmizerany:pat:c068ca2:pat \
		collectd:go-collectd:9fc824c:go_collectd \
		dgryski:go-bits:2ad8d70:go_bits \
		dgryski:go-bitstream:7d46cd2:go_bitstream \
		dominikh:go-js-dom:24aa052:go_js_dom \
		fsnotify:fsnotify:fd9ec7d:fsnotify \
		go-pipe:pipe:3c2ca4d:pipe \
		golang:crypto:c197bcf:crypto \
		golang:net:6acef71:net \
		golang:snappy:d9eb7a3:snappy \
		golang:tools:fc2b74b:tools \
		golang:sys:b699b70:sys \
		gopherjs:gopherjs:e34a5cd:gopherjs \
		jwilder:encoding:4dada27:encoding \
		kardianos:osext:c2c54e5:osext \
		microcosm-cc:bluemonday:f77f16f:bluemonday \
		neelance:sourcemap:8c68805:sourcemap \
		paulbellamy:ratecounter:5a11f58:ratecounter \
		peterh:liner:8975875:liner \
		rakyll:statik:274df12:statik \
		retailnext:hllpp:38a7bb7:hllpp \
		russross:blackfriday:5f33e7b:blackfriday \
		sergi:go-diff:552b4e9:go_diff \
		shurcooL:github_flavored_markdown:7bcab91:github_flavored_markdown \
		shurcooL:gopherjslib:feb6d39:gopherjslib \
		shurcooL:highlight_diff:d3b292e:highlight_diff \
		shurcooL:highlight_go:7867c2d:highlight_go \
		shurcooL:httpfs:01ca90b:httpfs \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized_anchor_name \
		sourcegraph:annotate:f4cad6c:annotate \
		sourcegraph:syntaxhighlight:c95ac47:syntaxhighlight \
		stretchr:testify:18a02ba:testify

SUB_FILES=	kapacitord
SUB_LIST+=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}
PLIST_SUB=	KAPACITORD_PIDDIR=${KAPACITORD_PIDDIR}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${MKDIR} ${WRKSRC}/src/github.com/bmizerany
	@${MKDIR} ${WRKSRC}/src/github.com/dgryski
	@${MKDIR} ${WRKSRC}/src/github.com/fsnotify
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/gopherjs
	@${MKDIR} ${WRKSRC}/src/github.com/jwilder
	@${MKDIR} ${WRKSRC}/src/github.com/kardianos
	@${MKDIR} ${WRKSRC}/src/github.com/microcosm-cc
	@${MKDIR} ${WRKSRC}/src/github.com/neelance
	@${MKDIR} ${WRKSRC}/src/github.com/paulbellamy
	@${MKDIR} ${WRKSRC}/src/github.com/peterh
	@${MKDIR} ${WRKSRC}/src/github.com/rakyll
	@${MKDIR} ${WRKSRC}/src/github.com/retailnext
	@${MKDIR} ${WRKSRC}/src/github.com/russross
	@${MKDIR} ${WRKSRC}/src/github.com/sergi
	@${MKDIR} ${WRKSRC}/src/github.com/shurcooL
	@${MKDIR} ${WRKSRC}/src/github.com/sourcegraph
	@${MKDIR} ${WRKSRC}/src/github.com/stretchr
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/honnef.co/go/js
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
	@${MV} ${WRKSRC_annotate} ${WRKSRC}/src/github.com/sourcegraph/annotate
	@${MV} ${WRKSRC_blackfriday} ${WRKSRC}/src/github.com/russross/blackfriday
	@${MV} ${WRKSRC_bluemonday} ${WRKSRC}/src/github.com/microcosm-cc/bluemonday
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_encoding} ${WRKSRC}/src/github.com/jwilder/encoding
	@${MV} ${WRKSRC_fsnotify} ${WRKSRC}/src/github.com/fsnotify/fsnotify
	@${MV} ${WRKSRC_github_flavored_markdown} ${WRKSRC}/src/github.com/shurcooL/github_flavored_markdown
	@${MV} ${WRKSRC_go_bitstream} ${WRKSRC}/src/github.com/dgryski/go-bitstream
	@${MV} ${WRKSRC_go_bits} ${WRKSRC}/src/github.com/dgryski/go-bits
	@${MV} ${WRKSRC_go_collectd} ${WRKSRC}/src/collectd.org
	@${MV} ${WRKSRC_go_diff} ${WRKSRC}/src/github.com/sergi/go-diff
	@${MV} ${WRKSRC_go_js_dom} ${WRKSRC}/src/honnef.co/go/js/dom
	@${MV} ${WRKSRC_gopherjslib} ${WRKSRC}/src/github.com/shurcooL/gopherjslib
	@${MV} ${WRKSRC_gopherjs} ${WRKSRC}/src/github.com/gopherjs/gopherjs
	@${MV} ${WRKSRC_highlight_diff} ${WRKSRC}/src/github.com/shurcooL/highlight_diff
	@${MV} ${WRKSRC_highlight_go} ${WRKSRC}/src/github.com/shurcooL/highlight_go
	@${MV} ${WRKSRC_hllpp} ${WRKSRC}/src/github.com/retailnext/hllpp
	@${MV} ${WRKSRC_httpfs} ${WRKSRC}/src/github.com/shurcooL/httpfs
	@${MV} ${WRKSRC_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/kardianos/osext
	@${MV} ${WRKSRC_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_pipe} ${WRKSRC}/src/gopkg.in/pipe.v2
	@${MV} ${WRKSRC_ratecounter} ${WRKSRC}/src/github.com/paulbellamy/ratecounter
	@${MV} ${WRKSRC_sanitized_anchor_name} ${WRKSRC}/src/github.com/shurcooL/sanitized_anchor_name
	@${MV} ${WRKSRC_snappy} ${WRKSRC}/src/github.com/golang/snappy
	@${MV} ${WRKSRC_sourcemap} ${WRKSRC}/src/github.com/neelance/sourcemap
	@${MV} ${WRKSRC_statik} ${WRKSRC}/src/github.com/rakyll/statik
	@${MV} ${WRKSRC_syntaxhighlight} ${WRKSRC}/src/github.com/sourcegraph/syntaxhighlight
	@${MV} ${WRKSRC_sys} ${WRKSRC}/src/golang.org/x/sys
	@${MV} ${WRKSRC_testify} ${WRKSRC}/src/github.com/stretchr/testify
	@${MV} ${WRKSRC_tools} ${WRKSRC}/src/golang.org/x/tools

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
