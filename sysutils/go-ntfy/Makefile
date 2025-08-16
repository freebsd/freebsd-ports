PORTNAME=	ntfy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
PKGNAMEPREFIX=	go-
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Send push notifications to your phone or desktop using PUT/POST
WWW=		https://ntfy.sh

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	binwiederhier

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/binwiederhier/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.version=${DISTVERSION}' \
			-X 'main.commit=${GITID}' \
			-X 'main.date=${BUILD_DATE}'"

CONFLICTS_INSTALL=	sysutils/ntfy

PLIST_FILES=	"@sample ${ETCDIR}/client.yml.sample" \
		"@sample ${ETCDIR}/server.yml.sample" \
		bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-material>=0:textproc/py-mkdocs-material@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mkdocs-minify-plugin>=0:textproc/py-mkdocs-minify-plugin@${PY_FLAVOR}
DOCS_USES=		python

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse --short HEAD'
# in the ntfy repository to get the value of GITID.
GITID=		eac523dc

BUILD_DATE=	$$(date -u "+%Y-%m-%dT%H:%M:%SZ")

post-patch:
	@${GREP} -rl "/etc/${PORTNAME}" ${WRKSRC}/cmd \
		| ${XARGS} ${REINPLACE_CMD} -e 's#/etc/${PORTNAME}#${ETCDIR}#g'

pre-build:
	@${MKDIR} ${WRKSRC}/server/docs
	${TOUCH} ${WRKSRC}/server/docs/index.html
	${RM} -r ${WRKSRC}/server/site
	@${MKDIR} ${WRKSRC}/server/site
	@cd ${WRKDIR}/ntfy-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/server/site

pre-build-DOCS-on:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} mkdocs build

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/server/server.yml ${STAGEDIR}${ETCDIR}/server.yml.sample
	${INSTALL_DATA} ${WRKSRC}/client/client.yml ${STAGEDIR}${ETCDIR}/client.yml.sample

.include <bsd.port.mk>
