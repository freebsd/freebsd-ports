PORTNAME=	amazon-ssm-plugin
DISTVERSION=	1.2.398.0
CATEGORIES=	sysutils

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Amazon AWS Manages shell experience using SSM APIs
WWW=		https://github.com/aws/session-manager-plugin/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	aws:devel/py-awscli@${PY_FLAVOR}

USES=		go python:env
GO_BUILDFLAGS=	-ldflags "-s -w"
GO_TARGET=	src/sessionmanagerplugin-main/main.go:${PREFIX}/bin/session-manager-plugin \
		src/ssmcli-main/main.go:${PREFIX}/bin/ssmcli

USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_PROJECT=	session-manager-plugin
GH_TAGNAME=	${DISTVERSION}
GH_SUBDIR=	${GH_PROJECT}

PORTDOCS=	NOTICE README.md RELEASENOTES.md THIRD-PARTY VERSION
PLIST_FILES=	${ETCDIR}/sessionmanagerplugin/seelog.xml.template \
		${ETCDIR}/SSMCLI/seelog.xml.template \
		bin/session-manager-plugin \
		bin/ssmcli \
		'@dir /var/log/amazon-ssm-plugin'

LOGDIR=		${DESTDIR}/var/log/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	${MKDIR} ${WRKDIR}/src
	${LN} -s ${WRKSRC} ${GO_WRKSRC}
	${MKDIR} ${WRKSRC}/vendor/src/github.com/aws/session-manager-plugin
	${LN} -s ${WRKSRC}/vendor/src/* ${GO_WRKSRC}/vendor/
	${LN} -s ${WRKSRC}/src          ${GO_WRKSRC}/vendor/github.com/aws/session-manager-plugin/

post-patch:
	${REINPLACE_CMD} -e 's|%%VERSION%%|${DISTVERSION}|' ${WRKSRC}/src/version/version.go
	${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g; s|%%LOGDIR%%|${LOGDIR}|g' ${WRKSRC}/seelog_unix.xml
	${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g; s|%%LOGDIR%%|${LOGDIR}|g' ${WRKSRC}/src/log/log_unix.go

post-install:
	@${MKDIR} ${STAGEDIR}${LOGDIR} ${STAGEDIR}${ETCDIR}/SSMCLI ${STAGEDIR}${ETCDIR}/sessionmanagerplugin
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${ETCDIR}/SSMCLI/seelog.xml.template
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${ETCDIR}/sessionmanagerplugin/seelog.xml.template

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
