PORTNAME=	amqpcat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		cloudamqp-amq-protocol.cr-v1.1.15_GH0.tar.gz \
		cloudamqp-amqp-client.cr-v1.3.1_GH0.tar.gz

MAINTAINER=	dch@FreeBSD.org
COMMENT=	CLI tool for publishing to and consuming from AMQP servers
WWW=		https://github.com/cloudamqp/amqpcat

LICENSE=	MIT

BUILD_DEPENDS=	crystal:lang/crystal \
		help2man:misc/help2man \
		shards:devel/shards

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	cloudamqp
GH_TUPLE=	cloudamqp:amq-protocol.cr:v1.1.15:proto/deps/amq-protocol.cr \
		cloudamqp:amqp-client.cr:v1.3.1:client/deps/amqp-client.cr

PLIST_FILES=	bin/amqpcat \
		share/man/man1/amqpcat.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

SHARDS_ENV=	--time --verbose --production --release --no-color --stats \
		--static

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

do-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/bin/shards lock ${SHARDS_ENV} && \
		${LOCALBASE}/bin/shards build ${SHARDS_ENV})
	help2man -Nn "CLI tool to publish to and consume from AMQP servers" \
		${WRKSRC}/bin/amqpcat -o ${WRKDIR}/amqpcat.1

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bin/amqpcat \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/amqpcat.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
