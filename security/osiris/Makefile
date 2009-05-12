# New ports collection Makefile for: 	osiris
# Date created:				10, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	osiris
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	The Shmoo client/server host integrity checker

OPTIONS=	OSIRISMD "Enable to build the management daemon" off \
		OSIRISD "Enable to build the osirisd scan agent" on \
		PRINTDB "Build database print tool" off \
		CLI "Enable to build the management CLI" off

GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.if defined(WITH_OSIRISMD)
PLIST_SUB+=	OSIRISMD=""
.else
PLIST_SUB+=	OSIRISMD="@comment "
.endif
.if defined(WITHOUT_OSIRISD)
PLIST_SUB+=	OSIRISD="@comment "
.else
PLIST_SUB+=	OSIRISD=""
.endif
.if defined(WITH_CLI)
PLIST_SUB+=	CLI=""
.else
PLIST_SUB+=	CLI="@comment "
.endif
.if defined(WITH_PRINTDB)
PLIST_SUB+=	PRINTDB=""
.else
PLIST_SUB+=	PRINTDB="@comment "
.endif

post-build:
.if defined(WITH_PRINTDB)
	cd ${WRKSRC}/src/tools && ${MAKE}
.endif

do-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/osiris
.if defined(WITH_CLI)
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/osiris ${PREFIX}/sbin
.endif
.if defined(WITH_PRINTDB)
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/printdb ${PREFIX}/bin
.endif
.if !defined(WITHOUT_OSIRISD)
	${SED} -e 's|@INSTALLDIR@|${PREFIX}/sbin|g' \
		-e 's|@OSIRISDIR@|${PREFIX}/osiris|g' \
		${WRKSRC}/src/install/freebsd/osirisd.in > \
		${WRKSRC}/src/install/freebsd/osirisd.sh
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirisd/osirisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirisd.sh \
		${PREFIX}/etc/rc.d
.endif
.if defined(WITH_OSIRISMD)
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
