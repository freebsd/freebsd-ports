# Created by: Nikolai Lifanov <lifanov@FreeBSD.org> and Ben Woods <woodsb02@FreeBSD.org>

PORTNAME=	zrepl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	ZFS dataset replication tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	zrepl

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w\
		-X ${GO_MODULE}/version.${PORTNAME}Version=${DISTVERSIONFULL}"

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		EXAMPLES MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.8.5,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_USES=		gmake python:build,3.6+
MANPAGES_PLIST_FILES=	man/man1/zrepl.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1300079
USES+=		ncurses
.else
USES+=		ncurses:port
CFLAGS+=	-I${LOCALBASE}/include/ncurses
.endif

.if ${OPSYS} == "FreeBSD"
SUB_LIST+=	DAEMON_LOGGING="-S -l \$${zrepl_facility} -s \$${zrepl_priority} -T \$${name}"
.else
SUB_LIST+=	DAEMON_LOGGING=""
.endif

post-build-MANPAGES-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} man

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/syslog.d \
		${STAGEDIR}/var/run/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_DATA} ${FILESDIR}/syslog.conf ${STAGEDIR}${EXAMPLESDIR}/syslog.conf
	${INSTALL_DATA} ${FILESDIR}/zrepl.yml ${STAGEDIR}${ETCDIR}/zrepl.yml.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/hooks
	(cd ${WRKSRC}/config/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/dist/grafana/grafana-prometheus-zrepl.json ${STAGEDIR}${EXAMPLESDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/zrepl.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
