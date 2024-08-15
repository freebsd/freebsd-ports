PORTNAME=	amazon-ssm-plugin
DISTVERSION=	1.2.633.0
PORTREVISION=	2
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
GH_SUBDIR=	${GH_PROJECT}
GH_TUPLE=	eiannone:keyboard:6d2a597fd0f1:eiannone_keyboard/vendor/github.com/eiannone/keyboard \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gorilla:websocket:e8629af678b7:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		stretchr:objx:cbeaeb16a013:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:6cb3b85ef5a0:stretchr_testify/vendor/github.com/stretchr/testify \
		twinj:uuid:70cac2bcd273:twinj_uuid/vendor/github.com/twinj/uuid \
		xtaci:smux:09e2c01560df:xtaci_smux/vendor/github.com/xtaci/smux
#shrinked?#	aws:aws-sdk-go:v1.49.8:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go
#customized#	cihub:seelog:c510775bb50d:cihub_seelog/vendor/github.com/cihub/seelog

PORTDOCS=	NOTICE README.md RELEASENOTES.md THIRD-PARTY VERSION
PLIST_FILES=	${ETCDIR}/sessionmanagerplugin/seelog.xml.template \
		${ETCDIR}/SSMCLI/seelog.xml.template \
		bin/session-manager-plugin \
		bin/ssmcli \
		'@dir /var/log/amazon-ssm-plugin'

LOGDIR=		${DESTDIR}/var/log/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKDIR}/src
	@${LN} -s ${WRKSRC} ${GO_WRKSRC}
	${MKDIR} ${WRKSRC}/vendor/github.com/aws/session-manager-plugin
	${LN} -s src/golang.org                      ${GO_WRKSRC}/vendor/
	${LN} -s ../../../../src                     ${GO_WRKSRC}/vendor/github.com/aws/session-manager-plugin/
	${LN} -s ../src/github.com/cihub             ${GO_WRKSRC}/vendor/github.com/
	${LN} -s ../../src/github.com/aws/aws-sdk-go ${GO_WRKSRC}/vendor/github.com/aws/

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
