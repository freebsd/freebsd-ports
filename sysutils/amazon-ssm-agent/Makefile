# $FreeBSD$

PORTNAME=	amazon-ssm-agent
PORTVERSION=	2.3.612.0
PORTREVISION=	1
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

post-patch:
	${LN} -s ${WRKSRC}/vendor/src/* ${WRKSRC}/vendor/

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/amazon-ssm-agent.json.template ${STAGEDIR}${PREFIX}/etc/amazon/ssm
	${INSTALL_DATA} ${WRKSRC}/seelog_unix.xml ${STAGEDIR}${PREFIX}/etc/amazon/ssm/seelog_unix.xml.template

.include <bsd.port.mk>
