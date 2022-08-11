PORTNAME=		sensu-go
DISTVERSION=		5.11.1
PORTREVISION=		4
CATEGORIES=		sysutils

MAINTAINER=		jp+ports@supplntr.io
COMMENT=		Ephemeral infrastructure and distributed applications monitoring

LICENSE=		APACHE20

ONLY_FOR_ARCHS=		amd64 i386
BUILD_DEPENDS=		bash:shells/bash

USES=			go
USE_GITHUB=		yes
GH_ACCOUNT=		sensu

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${GH_PROJECT}

OPTIONS_DEFINE=		SENSU_AGENT SENSU_CLI SENSU_BE
OPTIONS_DEFAULT=	SENSU_AGENT
OPTIONS_SUB=		yes

SENSU_AGENT_DESC=	Install sensu-agent daemon
SENSU_AGENT_VARS=	GO_TARGETS+=agent GO_BIN_TARGETS+=sensu-agent \
			USE_RC_SUBR+=sensu-agent

SENSU_CLI_DESC=		Install sensuctl binary
SENSU_CLI_VARS=		GO_TARGETS+=cli GO_BIN_TARGETS+=sensuctl

SENSU_BE_DESC=		Install sensu-backend daemon (unsupported)
SENSU_BE_VARS=		GO_TARGETS+=backend GO_BIN_TARGETS+=sensu-backend \
			USE_RC_SUBR+=sensu-backend
SENSU_BE_BROKEN=	Currently not tested under FreeBSD

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/git rev/d' ${WRKSRC}/build.sh
	@${REINPLACE_CMD} '/exec.Command("git"/d' ${WRKSRC}/version/cmd/version/version.go

do-build:
.for GO_TARGET in ${GO_TARGETS}
	@(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ./build.sh build_${GO_TARGET})
.endfor

do-install:
.for GO_BIN_TARGET in ${GO_BIN_TARGETS}
	${INSTALL_PROGRAM} ${GO_WRKSRC}/target/freebsd-${ARCH:S/^i//}/${GO_BIN_TARGET} ${STAGEDIR}${PREFIX}/bin
.endfor

post-install-SENSU_AGENT-on:
	${INSTALL_DATA} ${PATCHDIR}/sensu-agent.yml.sample \
		${STAGEDIR}${PREFIX}/etc/sensu-agent.yml.sample

post-install-SENSU_BE-on:
	${INSTALL_DATA} ${PATCHDIR}/sensu-backend.yml.sample \
		${STAGEDIR}${PREFIX}/etc/sensu-backend.yml.sample

.include <bsd.port.mk>
