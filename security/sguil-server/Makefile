# New ports collection makefile for:	sguil-server
# Date created:				9 Oct 2006
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sguil-server
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sguil

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

RUN_DEPENDS=	p0f:${PORTSDIR}/net-mgmt/p0f \
		tcpflow:${PORTSDIR}/net/tcpflow \
		dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX
LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls

NO_BUILD=	yes
USE_RC_SUBR=	sguild.sh
TCLSH_CMD?=	${PREFIX}/bin/tclsh8.4
SGUILDIR?=	sguil-server
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
PATCH_WRKSRC=	${WRKSRC}/server
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	SGUILDIR=${SGUILDIR} TCLSH=${TCLSH_CMD} CURDIR=${.CURDIR} \
		WRKSRC=${WRKSRC} DOCSDIR=${DOCSDIR}
LIBRARIES=	SguildAccess.tcl SguildGenericDB.tcl SguildReportBuilder.tcl \
		SguildAutoCat.tcl SguildGenericEvent.tcl SguildSendComms.tcl \
		SguildClientCmdRcvd.tcl SguildHealthChecks.tcl SguildSensorAgentComms.tcl \
		SguildConnect.tcl SguildLoaderd.tcl SguildSensorCmdRcvd.tcl \
		SguildCreateDB.tcl SguildMysqlMerge.tcl SguildTranscript.tcl \
		SguildEmailEvent.tcl SguildPadsLib.tcl SguildUtils.tcl \
		SguildEvent.tcl SguildQueryd.tcl
SCRIPTS=	create_ruledb.sql update_0.7.tcl update_sguildb_v7-v8.sql \
		create_sguildb.sql update_sguildb_v10-v11.sql update_sguildb_v8-v9.sql \
		migrate_event.tcl update_sguildb_v11-v12.sql update_sguildb_v9-v10.sql \
		migrate_sancp.tcl update_sguildb_v5-v6.sql sancp_cleanup.tcl update_sguildb_v6-v7.sql
CONFS=		autocat.conf sguild.access sguild.conf sguild.email sguild.queries sguild.reports sguild.users

PORTDOCS=	CHANGES FAQ INSTALL INSTALL.openbsd LICENSE.QPL \
		OPENSSL.README TODO UPGRADE USAGE sguildb.dia

OPTIONS=	MYSQL50 "Install mysql50 server" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL50)
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql50-server
.endif

MYSQLTCL_VER!=	cd ${PORTSDIR}/databases/mysqltcl && ${MAKE} -V PORTVERSION

RUN_DEPENDS+=	${LOCALBASE}/lib/mysqltcl-${MYSQLTCL_VER}:${PORTSDIR}/databases/mysqltcl

post-patch:
.for f in archive_sguildb.tcl sguild contrib/incident_report.tcl
	@${REINPLACE_CMD} -e 's:exec tclsh:exec ${TCLSH_CMD}:g' ${WRKSRC}/server/${f}
.endfor

pre-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif
	@${MKDIR} ${PREFIX}/etc/${SGUILDIR}
	@${MKDIR} ${PREFIX}/lib/${SGUILDIR}
	@${MKDIR} ${PREFIX}/share/${SGUILDIR}
	@${MKDIR} /var/run/${SGUILDIR}
do-install:
.for f in archive_sguildb.tcl sguild
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/server/${f} ${PREFIX}/bin/${f}
.endfor
.for f in incident_report.tcl
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/server/contrib/${f} ${PREFIX}/bin/${f}
.endfor
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/server/${f} ${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.for f in ${LIBRARIES}
	${INSTALL_DATA} ${WRKSRC}/server/lib/${f} ${PREFIX}/lib/${SGUILDIR}/${f}
.endfor
.for f in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/server/sql_scripts/${f} ${PREFIX}/share/${SGUILDIR}/${f}
.endfor
post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
