PORTNAME=	lavinmq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.5
CATEGORIES=	net

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Next-generation AMQP 0.9.1 based message broker
WWW=		https://www.lavinmq.com/

LICENSE=	APACHE20

BUILD_DEPENDS=	crystal:lang/crystal \
		help2man:misc/help2man \
		shards:devel/shards

USES=		pkgconfig ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	cloudamqp
GH_TUPLE=	\
		84codes:lz4.cr:6cc0d0096207821222317ee02ea23d5296ad4023:a/deps/lz4.cr \
		84codes:systemd.cr:v2.0.0:systemd/deps/systemd.cr \
		cloudamqp:amq-protocol.cr:v1.1.11:proto/deps/amq-protocol.cr \
		cloudamqp:amqp-client.cr:v1.0.12:client/deps/amqp-client.cr \
		luislavena:radix:v0.4.1:radix/deps/radix \
		tbrand:router.cr:v0.2.8:router/deps/router.cr

USE_RC_SUBR=	lavinmq

USERS=		lavinmq
GROUPS=		lavinmq

PORTDOCS=	CHANGELOG.md NOTICE README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

SHARDS_ENV=	--time --verbose --production --release --no-color --stats \
		--static

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN=	fails to compile: undefined symbol: EVP_MD_size
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
		${WRKSRC}/extras/config.ini

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
	${INSTALL_DATA} ${WRKSRC}/extras/config.ini \
		${STAGEDIR}${ETCDIR}/config.ini.sample
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
