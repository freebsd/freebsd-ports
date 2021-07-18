PORTNAME=	crowdsec
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Crowdsec lightweight and collaborative security engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	crowdsec

GO_MODULE=	github.com/crowdsecurity/crowdsec

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.Version=v${PORTVERSION} \
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.System=freebsd \
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"

GO_TARGET=	./cmd/crowdsec \
		./cmd/crowdsec-cli

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} 's,/etc/crowdsec/,${ETCDIR}/,g' \
		${WRKSRC}/pkg/csconfig/config.go \
		${WRKSRC}/cmd/crowdsec-cli/machines.go \
		${WRKSRC}/cmd/crowdsec-cli/main.go \
		${WRKSRC}/cmd/crowdsec/main.go

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})

	@${MV} ${STAGEDIR}${ETCDIR}/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample

	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec-cli ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
