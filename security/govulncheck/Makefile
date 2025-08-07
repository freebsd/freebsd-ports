PORTNAME=	govulncheck
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	einar@isnic.is
COMMENT=	Database client and tools for the Go vulnerability database
WWW=		https://pkg.go.dev/golang.org/x/vuln/cmd/govulncheck

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,run

GO_MODULE=	golang.org/x/vuln
GO_TARGET=	./cmd/govulncheck

PLIST_FILES=	bin/govulncheck

post-patch:
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/scan/util.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/all_test.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/scan/run.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/test/packages.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/test/testenv.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/testenv/testenv.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/internal/vulncheck/packages.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/telemetry/internal/configstore/download.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/telemetry/internal/telemetry/dir.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/go/gcexportdata/gcexportdata.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/go/packages/packagestest/export.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/internal/gcimporter/exportdata.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/internal/gocommand/invoke.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/internal/goroot/importcfg.go
	@${REINPLACE_CMD} -e 's|%%GO_CMD%%|${GO_CMD}|g' ${WRKSRC}/vendor/golang.org/x/tools/internal/testenv/testenv.go

.include <bsd.port.mk>
