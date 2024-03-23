PORTNAME=	dwatch-json
DISTVERSION=	1.2
CATEGORIES=	sysutils

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	FreeBSD dwatch suite to produce JSON stats
WWW=		https://github.com/FrauBSD/dwatch-json

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dwatch
	${INSTALL_DATA} ${WRKSRC}/json-* ${STAGEDIR}${PREFIX}/libexec/dwatch
	${INSTALL_DATA} ${WRKSRC}/dwatch-json-io.conf ${STAGEDIR}${PREFIX}/etc/dwatch-json-io.conf.sample
	${INSTALL_DATA} ${WRKSRC}/dwatch-json-net.conf ${STAGEDIR}${PREFIX}/etc/dwatch-json-net.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKSRC}/grafio/cron.d/* ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKSRC}/grafnet/cron.d/* ${STAGEDIR}${PREFIX}/etc/cron.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/grafio
	${INSTALL_DATA} ${WRKSRC}/grafio/etc/* ${STAGEDIR}${PREFIX}/etc/grafio
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/grafnet
	${INSTALL_DATA} ${WRKSRC}/grafnet/etc/* ${STAGEDIR}${PREFIX}/etc/grafnet
	@${MKDIR} ${STAGEDIR}${PREFIX}/sbin
	@${LN} -s grafio ${STAGEDIR}${PREFIX}/sbin/gio
	@${LN} -s grafnet ${STAGEDIR}${PREFIX}/sbin/gn
	${INSTALL_SCRIPT} ${WRKSRC}/graf/logs ${STAGEDIR}${PREFIX}/sbin/grafio-logs
	${INSTALL_SCRIPT} ${WRKSRC}/graf/logs ${STAGEDIR}${PREFIX}/sbin/grafnet-logs
	${INSTALL_SCRIPT} ${WRKSRC}/graf/rotate ${STAGEDIR}${PREFIX}/sbin/grafio-rotate
	${INSTALL_SCRIPT} ${WRKSRC}/graf/rotate ${STAGEDIR}${PREFIX}/sbin/grafnet-rotate
	${INSTALL_SCRIPT} ${WRKSRC}/graf/stats ${STAGEDIR}${PREFIX}/sbin/grafio_stats
	${INSTALL_SCRIPT} ${WRKSRC}/graf/stats ${STAGEDIR}${PREFIX}/sbin/grafnet_stats
	${INSTALL_SCRIPT} ${WRKSRC}/grafio/grafio ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/grafio/rc.d/* ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/grafnet/grafnet ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/grafnet/rc.d/* ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/grafio/dashboards
	${INSTALL_DATA} ${WRKSRC}/grafio/dashboards/* ${STAGEDIR}${PREFIX}/share/examples/grafio/dashboards
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/grafnet/dashboards
	${INSTALL_DATA} ${WRKSRC}/grafnet/dashboards/* ${STAGEDIR}${PREFIX}/share/examples/grafnet/dashboards

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
