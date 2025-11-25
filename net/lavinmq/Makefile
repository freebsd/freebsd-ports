PORTNAME=	lavinmq
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	net

# JavaScripts
MASTER_SITES+=	https://github.com/chartjs/Chart.js/releases/download/v${_CHARTJS}/:chartjs \
		https://github.com/cloudamqp/amqp-client.js/releases/download/v${_AMQP_JS}/:amqpclient \
		https://moment.github.io/luxon/es6/:luxon \
		https://cdn.jsdelivr.net/npm/chartjs-adapter-luxon@${_LUXON_JS}/dist/:chartjsadapter \
		https://unpkg.com/@stoplight/elements@${_ELEMENTS}/:elements \
		https://raw.githubusercontent.com/eclipse-paho/paho.mqtt.javascript/master/src/:paho

DISTFILES+=	chart.js-${_CHARTJS}.tgz:chartjs \
		amqp-websocket-client.mjs:amqpclient \
		amqp-websocket-client.mjs.map:amqpclient \
		luxon.js:luxon \
		chartjs-adapter-luxon.esm.js:chartjsadapter \
		web-components.min.js:elements \
		styles.min.css:elements \
		paho-mqtt.js:paho

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		84codes-lz4.cr-${_LZ4}_GH0.tar.gz \
		84codes-systemd.cr-v2.0.0_GH0.tar.gz \
		cloudamqp-amq-protocol.cr-v${_AMQP_PROTO}_GH0.tar.gz \
		cloudamqp-amqp-client.cr-v${_AMQP_CLIENT}_GH0.tar.gz \
		84codes-mqtt-protocol.cr-${_MQTT}_GH0.tar.gz \
		chart.js-${_CHARTJS}.tgz

# Crystal library versions
_AMQP_CLIENT=		1.3.2
_AMQP_PROTO=		1.1.16
_LZ4=		96d714f7593c66ca7425872fd26c7b1286806d3d
_MQTT=		5cf504b32313b3b63eecde22e2a136b9b9935b8b

# JavaScript library versions
_AMQP_JS=		3.1.1
_CHARTJS=		4.0.1
_ELEMENTS=		8.2.0
_LUXON_JS=		1.3.1

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Next-generation AMQP 0.9.1 based message broker
WWW=		https://www.lavinmq.com/

LICENSE=	APACHE20

BUILD_DEPENDS=	crystal:lang/crystal \
		help2man:misc/help2man \
		shards:devel/shards
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2

USES=		pkgconfig ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	cloudamqp
GH_TUPLE=	84codes:lz4.cr:${_LZ4}:a/deps/lz4.cr \
		84codes:systemd.cr:v2.0.0:systemd/deps/systemd.cr \
		cloudamqp:amq-protocol.cr:v${_AMQP_PROTO}:proto/deps/amq-protocol.cr \
		cloudamqp:amqp-client.cr:v${_AMQP_CLIENT}:client/deps/amqp-client.cr \
		84codes:mqtt-protocol.cr:${_MQTT}:mqtt/deps/mqtt-protocol.cr

USE_RC_SUBR=	lavinmq

USERS=		lavinmq
GROUPS=		lavinmq

PORTDOCS=	CHANGELOG.md NOTICE README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

SHARDS_ENV=	--time --verbose --production --release --no-color --stats \
		-Dgc_none --error-on-warnings -Dpreview_mt -Dexecution_context

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN=		fails to compile: undefined symbol: EVP_MD_size
.endif

post-extract:
# force shards to use local paths, not git repos, for dependencies
	@${RM} ${WRKSRC}/shard.lock
	@${REINPLACE_CMD} -E \
		-e 's,github: .*/,path: deps/,' \
		-e '/branch:/d' \
		-e '/version: .>1/d' \
		${WRKSRC}/shard.yml \
		${WRKSRC}/deps/*/shard.yml
# switch config example into hier(5) compliance
	@${REINPLACE_CMD} -E \
		-e 's,/etc/,${PREFIX}/etc/,' \
		-e 's,/lib/,/db/,' \
		-e 's,/tmp/lavinmq-http.sock,/var/run/lavinmq/http.sock,' \
		-e 's,/tmp/lavinmq.sock,/var/run/lavinmq/amqp.sock,' \
		${WRKSRC}/extras/lavinmq.ini
# setup javaScript directories
	${MKDIR} ${WRKSRC}/static/js/lib \
		${WRKSRC}/static/js/lib/chunks
# extract Chart.js files from tarball
	${TAR} -xOf ${DISTDIR}/chart.js-${_CHARTJS}.tgz package/dist/chart.js \
		> ${WRKSRC}/static/js/lib/chart.js
	${TAR} -xOf ${DISTDIR}/chart.js-${_CHARTJS}.tgz package/dist/chunks/helpers.segment.js \
		> ${WRKSRC}/static/js/lib/chunks/helpers.segment.js
# copy AMQP WebSocket client files
	${CP} ${DISTDIR}/amqp-websocket-client.mjs ${WRKSRC}/static/js/lib/
	${CP} ${DISTDIR}/amqp-websocket-client.mjs.map ${WRKSRC}/static/js/lib/
# copy luxon and Chart.js adapter
	${CP} ${DISTDIR}/luxon.js ${WRKSRC}/static/js/lib/
	${CP} ${DISTDIR}/chartjs-adapter-luxon.esm.js ${WRKSRC}/static/js/lib/
	${SED} -i '' \
		-e "s|\(import { _adapters } from\).*|\1 './chart.js'|; s|\(import { DateTime } from\).*|\1 './luxon.js'|" \
		${WRKSRC}/static/js/lib/chartjs-adapter-luxon.esm.js
# copy stoplight Elements files
	${CP} ${DISTDIR}/web-components.min.js ${WRKSRC}/static/js/lib/elements-${_ELEMENTS}.js
	${CP} ${DISTDIR}/styles.min.css ${WRKSRC}/static/js/lib/elements-${_ELEMENTS}.css
# copy paho MQTT
	${CP} ${DISTDIR}/paho-mqtt.js ${WRKSRC}/static/js/lib/

do-build:
	${MKDIR} ${WRKDIR}/man1
	(cd ${WRKSRC} && \
		${LOCALBASE}/bin/shards lock ${SHARDS_ENV} && \
		${LOCALBASE}/bin/shards build ${SHARDS_ENV})
	help2man -Nn "fast and advanced message queue server" ${WRKSRC}/bin/lavinmq \
		-o ${WRKDIR}/man1/lavinmq.1
	help2man -Nn "control utility for lavinmq server" ${WRKSRC}/bin/lavinmqctl \
		-o ${WRKDIR}/man1/lavinmqctl.1
	help2man -Nn "performance testing tool for amqp servers" ${WRKSRC}/bin/lavinmqperf \
		-o ${WRKDIR}/man1/lavinmqperf.1

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/db/lavinmq \
		${STAGEDIR}/var/log/lavinmq \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/extras/lavinmq.ini \
		${STAGEDIR}${ETCDIR}/lavinmq.ini.sample
.for f in lavinmq lavinmqctl lavinmqperf
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/man1/${f}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
