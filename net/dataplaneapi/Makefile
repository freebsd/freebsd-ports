PORTNAME=	dataplaneapi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.3
CATEGORIES=	net

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	HAProxy Data Plane API
WWW=		https://github.com/haproxytech/${PORTNAME}

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	haproxytech

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/haproxytech/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.GitRepo=https://github.com/haproxytech/${PORTNAME}' \
			-X 'main.GitTag=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'main.GitCommit=${GITID}' \
			-X 'main.BuildTime=${BUILD_DATE}'"

PLIST_FILES=	"@sample(,,640) etc/dataplaneapi.yaml.sample" \
		bin/${PORTNAME}

PORTDOCS=	CONFIG.md README.md

OPTIONS_DEFINE=	DOCS

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse --short HEAD'
# in the Data Plane API repository to get the value of GITID.
GITID=		daff5f5e

BUILD_DATE=	$$(date -u "+%Y-%m-%dT%H:%M:%SZ")

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/configuration/configuration.go

post-install:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/dataplaneapi.yaml \
		> ${STAGEDIR}${PREFIX}/etc/dataplaneapi.yaml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/configuration/doc/README.md ${STAGEDIR}${DOCSDIR}/CONFIG.md

.include <bsd.port.mk>
