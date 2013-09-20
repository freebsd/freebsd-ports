# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sguil-server
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	SF/sguil/sguil/sguil-${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

RUN_DEPENDS=	p0f:${PORTSDIR}/net-mgmt/p0f \
		tcpflow:${PORTSDIR}/net/tcpflow \
		dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX
LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	Depend on databases/mysqltcl

LICENSE_NAME=	QPLv1.0
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.QPL
LICENSE_PERMS=	auto-accept

IS_INTERACTIVE=	yes
NO_BUILD=	yes
USE_RC_SUBR=	sguild
TCL_VER=	8.5
TCLSH=		tclsh${TCL_VER}
MYSQLTCL_CMDS=	cd ${PORTSDIR}/databases/mysqltcl && ${MAKE} -V PORTVERSION
SGUILDIR?=	sguild
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
PATCH_WRKSRC=	${WRKSRC}/server
PLIST_SUB=	SGUILDIR=${SGUILDIR}
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	SGUILDIR=${SGUILDIR} TCLSH=${TCLSH}
CONFS=	autocat.conf sguild.access sguild.email	sguild.reports sguild.conf sguild.queries sguild.users

PORTDOCS1=	README
PORTDOCS2=	CHANGES FAQ INSTALL INSTALL.openbsd OPENSSL.README TODO UPGRADE USAGE sguildb.dia

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
	@${ECHO_CMD} $$(${MYSQLTCL_CMDS})
	RUN_DEPENDS+=	${LOCALBASE}/lib/mysqltcl-${MYSQLTCL_VER}:${PORTSDIR}/databases/mysqltcl
.endif

post-patch:
	@${REINPLACE_CMD} 's|/bin/sh|/usr/local/bin/${TCLSH}|' \
		${PATCH_WRKSRC}/sguild

pre-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif
	@${MKDIR} ${PREFIX}/etc/${SGUILDIR}
	@${MKDIR} ${PREFIX}/lib/${SGUILDIR}
	@${MKDIR} ${PREFIX}/share/${SGUILDIR}
	@${MKDIR} ${PREFIX}/share/${SGUILDIR}/contrib
	@${MKDIR} /var/run/${SGUILDIR}
do-install:
	(cd ${WRKSRC}/server/lib && ${COPYTREE_BIN} \* ${PREFIX}/lib/${SGUILDIR})
	(cd ${WRKSRC}/server/sql_scripts && ${COPYTREE_SHARE} \* ${PREFIX}/share/${SGUILDIR})
	(cd ${WRKSRC}/server/contrib && ${COPYTREE_SHARE} \* ${PREFIX}/share/${SGUILDIR}/contrib)
.for f in sguild
	${INSTALL_SCRIPT} -m 555 ${WRKSRC}/server/${f} ${PREFIX}/bin/${f}
.endfor
.for f in ${CONFS}
	${INSTALL_DATA} -m 441 ${PATCH_WRKSRC}/${f} ${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor

post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS1} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS2} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
