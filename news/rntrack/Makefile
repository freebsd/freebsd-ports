# $FreeBSD$

PORTNAME=	rntrack
PORTVERSION=	2.1.10
CATEGORIES=	news mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ftrack-as/RNtrack/${PORTVERSION}
DISTNAME=	rntrack-2_1_10-src

MAINTAINER=	admin@5034.ru
COMMENT=	FTN Messages tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	tar:bzip2

WRKSRC=	${WRKDIR}/${DISTNAME}
NO_WRKSUBDIR=	yes

USE_REINPLACE=	yes
ALL_TARGET=	${PORTNAME}
MAKEFILE=	${WRKSRC}/MakeFiles/FreeBSD/Makefile
MAKE_ENV=	CONFIG=${PREFIX}/etc/fido/rntrack/rntrack.cfg

DOCS=	FAQ_en FAQ_ru report.err report.err.ru

OPTIONS_DEFINE=	LOG_PID SCRIPTS SYSLOG_FORMAT

SCRIPTS_DESC=	Enable Perl scripts support
LOG_PID_DESC=	Enable pid logging
SYSLOG_FORMAT_DESC=	Use syslog-like log style

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSYSLOG_FORMAT}
MAKE_ARGS+=	ENABLE_SYSLOG_LOG_FORMAT=1
.endif

.if ${PORT_OPTIONS:MLOG_PID}
MAKE_ARGS+=	ENABLE_LOG_PID=1
.endif

.if ${PORT_OPTIONS:MSCRIPTS}
USES+=	perl5
MAKE_ARGS+=	ENABLE_SCRIPTS=1
.endif

pre-configure:
	${CP} ${WRKSRC}/MakeFiles/FreeBSD/Makefile ${WRKSRC}

pre-patch:
	${REINPLACE_CMD} -e "s@\.\./\.\./@@g" ${WRKSRC}/MakeFiles/FreeBSD/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fido/rntrack
	${INSTALL_PROGRAM} ${WRKSRC}/rntrack ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fido/rntrack/tpl
	${INSTALL_DATA} ${WRKSRC}/samples/node.cfg ${STAGEDIR}${PREFIX}/etc/fido/rntrack/rntrack.cfg-dist
	${INSTALL_DATA} ${WRKSRC}/samples/test.pl ${STAGEDIR}${PREFIX}/etc/fido/rntrack
	${INSTALL_DATA} ${WRKSRC}/samples/tpl/* ${STAGEDIR}${PREFIX}/etc/fido/rntrack/tpl
	${INSTALL_DATA} ${WRKSRC}/doc/rntrack.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fido/rntrack/tbl
.for f in alt2koi.tbl koi2alt.tbl
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}${PREFIX}/etc/fido/rntrack/tbl
.endfor
.for f in bignode.zip bignode2.zip node1042.zip node1157.zip node.cfg node2.cfg node3.cfg perl-test.cfg point.cfg point2.cfg traflog.tpl
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.include <bsd.port.mk>
