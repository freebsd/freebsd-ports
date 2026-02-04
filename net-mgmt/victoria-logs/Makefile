PORTNAME=	victoria-logs
PORTVERSION=	1.44.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
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
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_MOD_DIST=	github

USE_RC_SUBR?=	victoria_logs

MAKE_ENV=	PKG_TAG=v${PORTVERSION} GOOS=${OPSYS:tl} \
		BUILDINFO_TAG=tags-v${PORTVERSION}-victorialogs \
		DATEINFO_TAG=${_GET_DATE:sh} GOFLAGS=-buildvcs=false
ALL_TARGET=	${PORTNAME}-pure vlogscli-pure vmalert-pure

USERS=		victoria-logs
GROUPS=		victoria-logs
VICTORIA_DATA?=	/var/db/victoria-logs

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_USER=${USERS}

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_USER=${USERS}

OPTIONS_DEFINE=	DOCS

.if !defined(MASTERDIR)
do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME}-pure \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/vlogscli-pure \
		${STAGEDIR}${PREFIX}/bin/vlogscli
	@${MKDIR} ${STAGEDIR}${VICTORIA_DATA}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${INSTALL_WRKSRC}/docs/victorialogs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %Y%m%d-%H%M%S ${WRKSRC}/.gitignore
