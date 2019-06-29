# $FreeBSD$

PORTNAME=	amazon-ssm-agent
PORTVERSION=	2.3.612.0
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Amazon Simple Systems Manager Agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_SUBDIR=	src/github.com/aws/amazon-ssm-agent

PLIST_FILES=	etc/amazon/ssm/amazon-ssm-agent.json.template	\
		etc/amazon/ssm/seelog_unix.xml.template		\
		sbin/amazon-ssm-agent				\
		sbin/ssm-document-worker			\
		sbin/ssm-session-worker				\
		sbin/ssm-session-logger				\
		sbin/ssm-cli

USE_RC_SUBR=	amazon-ssm-agent

do-build:
	@cd ${WRKSRC};							\
	    ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o amazon-ssm-agent -v 				\
		agent/agent.go agent/agent_unix.go agent/agent_parser.go
	@cd ${WRKSRC};							\
	    ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o ssm-document-worker -v				\
		agent/framework/processor/executer/outofproc/worker/main.go
	@cd ${WRKSRC};							\
	    ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o ssm-session-worker -v				\
		agent/framework/processor/executer/outofproc/sessionworker/main.go
	@cd ${WRKSRC};							\
	    ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o ssm-session-logger -v				\
		agent/session/logging/main.go
	@cd ${WRKSRC};							\
	    ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o ssm-cli -v agent/cli-main/cli-main.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amazon-ssm-agent ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ssm-document-worker ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ssm-session-worker ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ssm-session-logger ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ssm-cli ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/amazon-ssm-agent.json.template ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${PREFIX}/etc/amazon/ssm/seelog_unix.xml.template

.include <bsd.port.mk>
