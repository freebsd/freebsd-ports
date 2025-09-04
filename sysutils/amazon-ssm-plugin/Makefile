PORTNAME=	amazon-ssm-plugin
DISTVERSION=	1.2.707.0
PORTREVISION=	7
CATEGORIES=	sysutils

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Amazon AWS Manages shell experience using SSM APIs
WWW=		https://github.com/aws/session-manager-plugin/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	aws:devel/py-awscli@${PY_FLAVOR}

USES=		go python:env
USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_PROJECT=	session-manager-plugin
GH_SUBDIR=	${GH_PROJECT}
GH_TUPLE=	aws:aws-sdk-go:v1.54.10:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		eiannone:keyboard:6d2a597fd0f1:eiannone_keyboard/vendor/github.com/eiannone/keyboard \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gorilla:websocket:e8629af678b7:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		twinj:uuid:70cac2bcd273:twinj_uuid/vendor/github.com/twinj/uuid \
		xtaci:smux:09e2c01560df:xtaci_smux/vendor/github.com/xtaci/smux
#customized#	cihub:seelog:c510775bb50d:cihub_seelog/vendor/github.com/cihub/seelog

GO_TARGET=	src/sessionmanagerplugin-main/main.go:${PREFIX}/bin/session-manager-plugin \
		src/ssmcli-main/main.go:${PREFIX}/bin/ssmcli
GO_BUILDFLAGS=	-ldflags "-s -w"

PLIST_FILES=	${ETCDIR}/sessionmanagerplugin/seelog.xml.template \
		${ETCDIR}/SSMCLI/seelog.xml.template \
		'@dir /var/log/amazon-ssm-plugin' \
		bin/session-manager-plugin \
		bin/ssmcli
PORTDOCS=	NOTICE README.md RELEASENOTES.md THIRD-PARTY VERSION

LOGDIR=		${DESTDIR}/var/log/${PORTNAME}

OPTIONS_DEFINE=	DOCS

RECOMMEND_VERSION=	1.3.0.0

post-extract:
	@${MKDIR} ${WRKDIR}/src
	@${LN} -s ${WRKSRC} ${GO_WRKSRC}
	${MKDIR}  ${WRKDIR}/src/vendor
	${MV}     ${WRKSRC}/vendor/github.com           ${WRKDIR}/src/vendor/
	${LN} -s  ${WRKSRC}/vendor/src/github.com/cihub ${WRKDIR}/src/vendor/github.com/
	${LN} -s  ${WRKSRC}/vendor/src/golang.org       ${WRKDIR}/src/vendor/
	${LN} -s  ${WRKSRC}/vendor/src/gopkg.in         ${WRKDIR}/src/vendor/
	${LN} -s  ${WRKSRC}                             ${WRKDIR}/src/vendor/github.com/${GH_ACCOUNT}/${GH_PROJECT}

post-patch:
	${REINPLACE_CMD} -e 's|%%VERSION%%|${RECOMMEND_VERSION}|' ${WRKSRC}/VERSION
	${REINPLACE_CMD} -e 's|%%VERSION%%|${RECOMMEND_VERSION}|' ${WRKSRC}/src/version/version.go
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
