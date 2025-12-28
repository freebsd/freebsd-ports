PORTNAME=	vmutils

COMMENT=	Ancillary utilities and agent for VictoriaMetrics

USE_RC_SUBR=	vmagent

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

VMAGENT_DATA?=	/var/db/vmagent

SUB_LIST+=	VMAGENT_DATA=${VMAGENT_DATA}
PLIST_SUB+=	VMAGENT_DATA=${VMAGENT_DATA}

do-install:
.for p in agent alert auth backup ctl restore
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vm${p}-pure \
		${STAGEDIR}${PREFIX}/bin/vm${p}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/prometheus
	${INSTALL_DATA} ${FILESDIR}/prometheus.yml.sample \
		${STAGEDIR}${PREFIX}/etc/prometheus
	@${MKDIR} ${STAGEDIR}${VMAGENT_DATA}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${INSTALL_WRKSRC}/docs/victoriametrics/vm* ${STAGEDIR}${DOCSDIR}

MASTERDIR=	${.CURDIR}/../victoria-metrics

.include "${MASTERDIR}/Makefile"
