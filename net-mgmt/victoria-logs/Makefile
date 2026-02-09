PORTNAME=	victoria-logs
PORTVERSION=	1.45.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Fast and easy-to-use, open source logs solution
WWW=		https://victoriametrics.com/products/victorialogs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:1.25+,modules,no_targets

# we have to use github, as goproxy tags are wrong
# see https://github.com/VictoriaMetrics/VictoriaLogs/issues/1071
USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaLogs
USE_RC_SUBR?=	victoria_logs

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

MAKE_ENV=	BUILDINFO_TAG=tags-v${PORTVERSION}-victorialogs \
		DATEINFO_TAG=${_GET_DATE:sh} \
		GOFLAGS=-buildvcs=false \
		GOOS=${OPSYS:tl} \
		PKG_TAG=v${PORTVERSION}
ALL_TARGET=	${PORTNAME}-pure vlogscli-pure vmalert-pure

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_LOGS=${VICTORIA_LOGS} \
		VICTORIA_RUN=${VICTORIA_RUN} \
		VICTORIA_USER=${USERS}

USERS=		victoria-logs
GROUPS=		victoria-logs
VICTORIA_DATA?=	/var/db/victoria-logs
VICTORIA_LOGS?=	/var/log/victoria_logs
VICTORIA_RUN?=	/var/run/victoria_logs

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_LOGS=${VICTORIA_LOGS} \
		VICTORIA_RUN=${VICTORIA_RUN} \
		VICTORIA_USER=${USERS}

OPTIONS_DEFINE=	DOCS

.if !defined(MASTERDIR)
do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME}-pure \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/vlogscli-pure \
		${STAGEDIR}${PREFIX}/bin/vlogscli
	@${MKDIR} ${STAGEDIR}${VICTORIA_DATA} ${STAGEDIR}${VICTORIA_LOGS} \
		${STAGEDIR}${VICTORIA_RUN}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${INSTALL_WRKSRC}/docs/victorialogs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %Y%m%d-%H%M%S ${WRKSRC}/.gitignore
