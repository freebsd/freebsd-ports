PORTNAME=	access-log-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
CATEGORIES=	www

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Prometheus exporter to convert webserver logs into metrics
WWW=		https://github.com/jkroepke/access-log-exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

EXTRACT_DEPENDS=	${BUILD_DEPENDS}

USES=		go:modules
USE_RC_SUBR=	access_log_exporter

GO_MODULE=	github.com/jkroepke/access-log-exporter
GO_TARGET=	./cmd/${PORTNAME}

SUB_FILES=	access_log_exporter

PLIST_FILES=	bin/access-log-exporter

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

EXAMPLES_PLIST_FILES+=	share/examples/${PORTNAME}/grafana-dashboard.json

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/access-log-exporter ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/packaging/etc/access-log-exporter/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample
	${ECHO} "@sample ${ETCDIR}/config.yaml.sample" >> ${TMPPLIST}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/grafana-dashboard.json ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
