PORTNAME=	otelcol-contrib
PORTVERSION=	0.138.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v${PORTVERSION}/
DISTFILES_amd64=	${PORTNAME}_${DISTVERSION}_linux_amd64.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	OpenTelemetry Collector Contrib
WWW=		https://github.com/open-telemetry/opentelemetry-collector-contrib/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

USES=		linux:rl9

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/otelcol-contrib \
		%%DATADIR%%/README.md \
		%%DATADIR%%/config.yaml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/config.yaml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
