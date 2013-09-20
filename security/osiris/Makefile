# $FreeBSD$

PORTNAME=	osiris
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	The Shmoo client/server host integrity checker

OPTIONS_DEFINE=	OSIRISMD OSIRISD PRINTDB CLI
OPTIONS_DEFAULT=	OSIRISD
OSIRISMD_DESC=	Enable to build the management daemon
OSIRISD_DESC=	Enable to build the osirisd scan agent
PRINTDB_DESC=	Build database print tool
CLI_DESC=	Enable to build the management CLI

GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.if ${PORT_OPTIONS:MOSIRISMD}
PLIST_SUB+=	OSIRISMD=""
.else
PLIST_SUB+=	OSIRISMD="@comment "
.endif
.if ! ${PORT_OPTIONS:MOSIRISD}
PLIST_SUB+=	OSIRISD="@comment "
.else
PLIST_SUB+=	OSIRISD=""
.endif
.if ${PORT_OPTIONS:MCLI}
PLIST_SUB+=	CLI=""
.else
PLIST_SUB+=	CLI="@comment "
.endif
.if ${PORT_OPTIONS:MPRINTDB}
PLIST_SUB+=	PRINTDB=""
.else
PLIST_SUB+=	PRINTDB="@comment "
.endif

post-build:
.if ${PORT_OPTIONS:MPRINTDB}
	cd ${WRKSRC}/src/tools && ${MAKE}
.endif

do-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/osiris
.if ${PORT_OPTIONS:MCLI}
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/osiris ${PREFIX}/sbin
.endif
.if ${PORT_OPTIONS:MPRINTDB}
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/printdb ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MOSIRISD}
	${SED} -e 's|@INSTALLDIR@|${PREFIX}/sbin|g' \
		-e 's|@OSIRISDIR@|${PREFIX}/osiris|g' \
		${WRKSRC}/src/install/freebsd/osirisd.in > \
		${WRKSRC}/src/install/freebsd/osirisd.sh
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirisd/osirisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirisd.sh \
		${PREFIX}/etc/rc.d
.endif
.if ${PORT_OPTIONS:MOSIRISMD}
	${SED} -e 's|@INSTALLDIR@|${PREFIX}/sbin|g' \
		-e 's|@OSIRISDIR@|${PREFIX}/osiris|g' \
		${WRKSRC}/src/install/freebsd/osirismd.in > \
		${WRKSRC}/src/install/freebsd/osirismd.sh
	@${MKDIR} ${PREFIX}/osiris/configs
.for os in aix bsdos darwin freebsd irix linux netbsd openbsd sunos \
	unix-generic windows2000 windowsnt windowsserver2003 windowsxp \
	wrt54g
	${INSTALL_DATA} ${WRKSRC}/src/configs/default.${os} \
		${PREFIX}/osiris/configs
.endfor
	${INSTALL_PROGRAM} -m 4755 -o osiris -g osiris \
		${WRKSRC}/src/osirismd/osirismd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirismd.sh \
		${PREFIX}/etc/rc.d
.endif
	${CHOWN} -R osiris:osiris ${PREFIX}/osiris

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
