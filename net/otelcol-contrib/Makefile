PORTNAME=	otelcol-contrib
PORTVERSION=	0.165.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_linux_${ARCH}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	OpenTelemetry Collector Contrib
WWW=		https://github.com/open-telemetry/opentelemetry-collector-contrib/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		cpe linux:rl9

CPE_VENDOR=	opentelemetry
CPE_PRODUCT=	opentelemetry_collector_contrib

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/otelcol-contrib \
		%%DATADIR%%/README.md \
		%%DATADIR%%/config.yaml

.if make(makesum)
.  for arch in ${ONLY_FOR_ARCHS}
DISTFILES+=	${PORTNAME}_${DISTVERSION}_linux_${arch:S/aarch64/arm64/}${EXTRACT_SUFX}
.  endfor
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/config.yaml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
