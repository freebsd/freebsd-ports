PORTNAME=	vault
DISTVERSIONPREFIX=	v
DISTVERSION=	1.20.0
CATEGORIES=	security
MASTER_SITES=	https://raw.githubusercontent.com/hashicorp/vault/${DISTVERSIONFULL}/ \
		LOCAL/bofh/security/${PORTNAME}/:web_ui
DISTFILES=	go.mod \
		api/go.mod \
		api/auth/approle/go.mod \
		api/auth/kubernetes/go.mod \
		api/auth/userpass/go.mod \
		sdk/go.mod \
		${PORTNAME}-web_ui-${DISTVERSION}${EXTRACT_SUFX}:web_ui

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for securely accessing secrets
WWW=		https://vaultproject.io/

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	fatal error: out of memory

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

.if defined(MAINTAINER_MODE)
EXTRACT_DEPENDS=npm-node20>0:www/npm-node20 \
		yarn-node20>0:www/yarn-node20
.endif

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
USE_RC_SUBR=	vault

GO_MODULE=	github.com/hashicorp/vault
GO_BUILDFLAGS=	-ldflags="-s \
		-X github.com/hashicorp/vault/version.GitCommit=${GITID} \
		-X github.com/hashicorp/vault/version.BuildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		" -tags "vault ui"

SUB_FILES=	pkg-message

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}

GITID=	6fdd6b59e97d97a9e19b0fb5304bf879c190295e

.include <bsd.port.pre.mk>

# Bring DISTINFO_FILE into scope so we can get the timestamp.
SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

post-patch:
	${CP} -Rf ${WRKDIR}/web_ui ${WRKSRC}/http/

.if defined(MAINTAINER_MODE)
_make-web_ui: extract
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} yarn
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm rebuild node-sass
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} yarn run build
	cd ${WRKDIR} && ${TAR} -czf \
		${PORTNAME}-web_ui-${DISTVERSION}${EXTRACT_SUFX} -C ${WRKSRC}/http web_ui
	scp ${WRKDIR}/${PORTNAME}-web_ui-${DISTVERSION}${EXTRACT_SUFX} \
		bofh@freefall.freebsd.org:public_distfiles/security/${PORTNAME}/
.endif

.include <bsd.port.post.mk>
