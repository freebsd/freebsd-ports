PORTNAME=	amazon-ssm-agent
PORTVERSION=	2.3.1205.0
PORTREVISION=	31
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Amazon Simple Systems Manager Agent
WWW=		https://github.com/aws/amazon-ssm-agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_SUBDIR=	src/github.com/aws/amazon-ssm-agent
GH_TUPLE=	creack:pty:v1.1.18:pty \
		golang:sys:v0.6.0:sys

GO_BUILDFLAGS=	-ldflags "-s -w"
GO_TARGET=	./agent:${PREFIX}/sbin/amazon-ssm-agent \
		./agent/framework/processor/executer/outofproc/worker:${PREFIX}/sbin/ssm-document-worker \
		./agent/framework/processor/executer/outofproc/sessionworker:${PREFIX}/sbin/ssm-session-worker \
		./agent/session/logging:${PREFIX}/sbin/ssm-session-logger \
		./agent/cli-main:${PREFIX}/sbin/ssm-cli

PLIST_FILES=	etc/amazon/ssm/amazon-ssm-agent.json.template	\
		etc/amazon/ssm/seelog_unix.xml.template		\
		sbin/amazon-ssm-agent				\
		sbin/ssm-document-worker			\
		sbin/ssm-session-worker				\
		sbin/ssm-session-logger				\
		sbin/ssm-cli

USE_RC_SUBR=	amazon-ssm-agent

pre-patch:
	${MKDIR} ${WRKSRC}/vendor/src/github.com/creack
	${LN} -s ${WRKSRC_pty} ${WRKSRC}/vendor/src/github.com/creack/pty
	${RM} -r ${WRKSRC}/vendor/src/golang.org/x/sys
	${LN} -s ${WRKSRC_sys} ${WRKSRC}/vendor/src/golang.org/x/sys

post-patch:
	${LN} -s ${WRKSRC}/vendor/src/* ${WRKSRC}/vendor/

pre-build:
# set package version
	cd ${GO_WRKSRC} && BRAZIL_PACKAGE_VERSION=${PORTVERSION} \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ./agent/version/versiongenerator/version-gen.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/amazon-ssm-agent.json.template ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${PREFIX}/etc/amazon/ssm/seelog_unix.xml.template

.include <bsd.port.mk>
