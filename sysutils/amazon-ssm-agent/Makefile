# $FreeBSD$

PORTNAME=	amazon-ssm-agent
PORTVERSION=	2.0.790.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Amazon Simple Systems Manager Agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_SUBDIR=	src/github.com/aws/amazon-ssm-agent

PLIST_FILES=	etc/amazon/ssm/amazon-ssm-agent.json.template	\
		etc/amazon/ssm/seelog_unix.xml.template		\
		sbin/amazon-ssm-agent

USE_RC_SUBR=	amazon-ssm-agent

do-build:
	@cd ${WRKSRC};							\
	    ${SETENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor CGO_ENABLED=0	\
	    go build -ldflags "-s -w" -o amazon-ssm-agent		\
	    agent/agent.go agent/agent_unix.go agent/agent_parser.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amazon-ssm-agent ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/amazon-ssm-agent.json.template ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${PREFIX}/etc/amazon/ssm/seelog_unix.xml.template

.include <bsd.port.mk>
