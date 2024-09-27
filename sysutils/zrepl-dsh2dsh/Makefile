PORTNAME=	zrepl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-dsh2dsh

MAINTAINER=	dsh@bamus.cz
COMMENT=	ZFS dataset replication tool (fork with more features)
WWW=		https://github.com/dsh2dsh/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules ncurses
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} -w -X github.com/dsh2dsh/${PORTNAME}/version.${PORTNAME}Version=${DISTVERSIONFULL}"

CONFLICTS_INSTALL=	${PORTNAME}

SUB_FILES=	pkg-message 500.${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.yml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.yml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/500.${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly/500.${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/hooks
	(cd ${WRKSRC}/config/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} \
		${WRKSRC}/dist/grafana/grafana-prometheus-${PORTNAME}.json \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
