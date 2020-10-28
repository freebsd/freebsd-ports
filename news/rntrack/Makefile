# $FreeBSD$

PORTNAME=	rntrack
PORTVERSION=	2.1.10
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ftrack-as/RNtrack/${PORTVERSION}
DISTNAME=	rntrack-2_1_10-src

MAINTAINER=	admin@5034.ru
COMMENT=	FTN Messages tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2

MAKE_ENV=	CONFIG=${ETCDIR}/rntrack.cfg

ETCDIR=		${PREFIX}/etc/fido

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/MakeFiles/FreeBSD

_DOCS=		FAQ_en FAQ_ru report.err report.err.ru

OPTIONS_DEFINE=	DOCS EXAMPLES LOG_PID SCRIPTS SYSLOG_FORMAT

LOG_PID_DESC=		Enable PID logging
SCRIPTS_DESC=		Enable Perl scripts support
SYSLOG_FORMAT_DESC=	Use syslog-like log style

LOG_PID_MAKE_ARGS=		ENABLE_LOG_PID=1
SCRIPTS_USES=			perl5
SCRIPTS_MAKE_ARGS=		ENABLE_SCRIPTS=1
SYSLOG_FORMAT_MAKE_ARGS=	ENABLE_SYSLOG_LOG_FORMAT=1

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/rntrack ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/tpl
	${INSTALL_DATA} ${WRKSRC}/samples/node.cfg ${STAGEDIR}${ETCDIR}/rntrack.cfg-dist
	${INSTALL_DATA} ${WRKSRC}/samples/test.pl ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/tpl/* ${STAGEDIR}${ETCDIR}/tpl
	${INSTALL_DATA} ${WRKSRC}/doc/rntrack.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${ETCDIR}/tbl
.for f in alt2koi.tbl koi2alt.tbl
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}${ETCDIR}/tbl
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in bignode.zip bignode2.zip node1042.zip node1157.zip node.cfg node2.cfg node3.cfg perl-test.cfg point.cfg point2.cfg traflog.tpl
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
