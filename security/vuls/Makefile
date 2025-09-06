PORTNAME=	vuls
DISTVERSIONPREFIX=v
DISTVERSION=	0.34.0
CATEGORIES=	security

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Agentless vulnerability scanner
WWW=		https://vuls.io

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/future-architect/vuls
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message periodic-vuls
SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS} GROUPS=${GROUPS}

USERS=		vuls
GROUPS=		vuls

NOT_FOR_ARCHS=			i386
NOT_FOR_ARCHS_REASON_i386=	https://gitlab.com/cznic/libc/-/issues/45

post-patch:
	@${REINPLACE_CMD} -e 's,%%ETCDIR%%,${ETCDIR},' \
		${WRKSRC}/subcmds/configtest.go \
		${WRKSRC}/subcmds/report_windows.go \
		${WRKSRC}/subcmds/report.go \
		${WRKSRC}/subcmds/saas.go \
		${WRKSRC}/subcmds/scan.go \
		${WRKSRC}/subcmds/server.go \
		${WRKSRC}/subcmds/tui.go

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/db/vuls/results \
		${STAGEDIR}/var/log/vuls \
		${STAGEDIR}${PREFIX}/etc/periodic/daily \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${FILESDIR}/config.toml \
		${STAGEDIR}${ETCDIR}/config.toml.sample
	${INSTALL_SCRIPT} ${WRKDIR}/periodic-${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/${PORTNAME}

.include <bsd.port.mk>
