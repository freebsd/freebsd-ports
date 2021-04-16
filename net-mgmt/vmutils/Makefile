# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	vmutils
COMMENT=	Ancillary utilities and agent for VictoriaMetrics

USE_RC_SUBR=	vmagent

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

do-install:
.for p in agent alert auth backup ctl restore
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vm${p}-pure \
		${STAGEDIR}${PREFIX}/bin/vm${p}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/vm* ${STAGEDIR}${DOCSDIR}

MASTERDIR=	${.CURDIR}/../victoria-metrics

.include "${MASTERDIR}/Makefile"
