PORTNAME=	rntrack
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.2
CATEGORIES=	news mail

MAINTAINER=	admin@5034.ru
COMMENT=	FTN Messages tracker
WWW=		https://github.com/vasilyevmax/rntrack/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++14-lang
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	vasilyevmax

MAKE_ENV=	CONFIG=${ETCDIR}/${PORTNAME}.cfg

ETCDIR=		${PREFIX}/etc/fido/${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/MakeFiles/FreeBSD

OPTIONS_DEFINE=	DOCS EXAMPLES LOG_PID SCRIPTS SYSLOG_FORMAT

LOG_PID_DESC=		Enable PID logging
SCRIPTS_DESC=		Enable Perl scripts support
SYSLOG_FORMAT_DESC=	Use syslog-like log style

LOG_PID_MAKE_ARGS=		ENABLE_LOG_PID=1
SCRIPTS_USES=			perl5
SCRIPTS_MAKE_ARGS=		ENABLE_SCRIPTS=1
SYSLOG_FORMAT_MAKE_ARGS=	ENABLE_SYSLOG_LOG_FORMAT=1

_DOCS=		FAQ_en FAQ_ru report.err report.err.ru
_EXAMPLES=	bignode.zip bignode2.zip node1042.zip node1157.zip \
		node.cfg node2.cfg node3.cfg perl-test.cfg \
		point.cfg point2.cfg traflog.tpl
_TBL=		alt2koi.tbl koi2alt.tbl

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}/tbl \
		 ${STAGEDIR}${ETCDIR}/tpl
	${INSTALL_DATA} ${WRKSRC}/samples/node.cfg ${STAGEDIR}${ETCDIR}/${PORTNAME}.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/samples/test.pl ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/tpl/* ${STAGEDIR}${ETCDIR}/tpl
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${_TBL:S|^|${WRKSRC}/samples/|} ${STAGEDIR}${ETCDIR}/tbl

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${_EXAMPLES:S|^|${WRKSRC}/samples/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
