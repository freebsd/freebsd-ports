PORTNAME=	littlefedi
DISTVERSION=	26.10.01
CATEGORIES=	www net-im
MASTER_SITES=	https://littlefedi.org/downloads/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	stefano@dragas.it
COMMENT=	Lightweight ActivityPub server with Mastodon-compatible API
WWW=		https://littlefedi.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	${GO_CMD}:lang/go${GO_SUFFIX}

FLAVORS=			sqlite pgsql
FLAVOR?=			${FLAVORS:[1]}
pgsql_PKGNAMESUFFIX=		-pgsql
pgsql_CONFLICTS_INSTALL=	${PORTNAME}
sqlite_CONFLICTS_INSTALL=	${PORTNAME}-pgsql

USES=		go:1.26+,modules

USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./cmd/littlefedi
GO_BUILDFLAGS=	-tags "${_LITTLEFEDI_TAGS}" \
		-ldflags="-s -w -X brew.bsd.cafe/littlecomputerpeople/littlefedi/internal/version.Version=${DISTVERSION}"
GO_TESTFLAGS=	-tags "${_LITTLEFEDI_TAGS}"

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		BLOG DOCS EXAMPLES S3
OPTIONS_DEFAULT=	BLOG DOCS EXAMPLES S3
BLOG_DESC=		Static blog support
S3_DESC=		S3 media storage support

BLOG_VARS=	_LITTLEFEDI_TAGS+=blog
S3_VARS=	_LITTLEFEDI_TAGS+=s3

.if ${FLAVOR} == pgsql
_LITTLEFEDI_TAGS+=	postgres
_LITTLEFEDI_CONFIG_SED=	-e 's|/var/lib/littlefedi|/var/db/littlefedi|g' -e \
			's|^dsn = .*|dsn = "postgresql://littlefedi:password@127.0.0.1/littlefedi?sslmode=disable"|'
.else
_LITTLEFEDI_CONFIG_SED=	-e 's|/var/lib/littlefedi|/var/db/littlefedi|g'
.endif

_GOMOD_DIR=	${GO_GOPATH}/${DISTNAME}

# the tarball is neither vendored nor using proxy.golang.org, deal with it
post-fetch:
	@${MKDIR} ${_GOMOD_DIR}
	@${TEST} -e ${_GOMOD_DIR}/go.mod || \
		${TAR} -xf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${_GOMOD_DIR} \
		--strip-components 1 ${WRKSRC:T}/go.mod ${WRKSRC:T}/go.sum
	@cd ${_GOMOD_DIR} && \
		${SETENVI} ${WRK_ENV} ${GO_ENV} GOPROXY=${GO_GOPROXY} \
		${GO_CMD} mod download -x all

post-extract:
	@cd ${GO_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} \
		${GO_CMD} mod vendor

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/db/${PORTNAME}
	${SED} ${_LITTLEFEDI_CONFIG_SED} \
		${WRKSRC}/config/littlefedi.production.toml \
		> \
		${STAGEDIR}${ETCDIR}/littlefedi.toml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md \
		${WRKSRC}/docs/*.md \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config/*.example \
		${WRKSRC}/packaging/Caddyfile* \
		${WRKSRC}/packaging/nginx-* \
		${WRKSRC}/packaging/littlefedi-proxy-headers.conf \
		${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/freebsd
	(cd ${WRKSRC}/packaging/freebsd && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/freebsd)

.include <bsd.port.mk>
