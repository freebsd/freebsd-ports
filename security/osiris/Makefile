# New ports collection Makefile for: 	osiris
# Date created:				10, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	osiris
PORTVERSION=	4.1.1
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The Shmoo client/server host integrity checker

OPTIONS=	OSIRISMD "Enable to build the management daemon" off \
		OSIRISD "Enable to build the osirisd scan agent" on \
		CLI "Enable to build the management CLI" off

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15

.include <bsd.port.pre.mk>

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

do-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.if defined(WITH_CLI)
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/osiris ${PREFIX}/sbin
.endif
.if !defined(WITHOUT_OSIRISD)
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/install/freebsd/osirisd.in > \
		${WRKSRC}/src/install/freebsd/osirisd.sh.sample
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirisd/osirisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirisd.sh.sample \
		${PREFIX}/etc/rc.d
.endif
.if defined(WITH_OSIRISMD)
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/install/freebsd/osirismd.in > \
		${WRKSRC}/src/install/freebsd/osirismd.sh.sample
	@${MKDIR} ${PREFIX}/osiris/configs
.for os in aix bsdos darwin freebsd irix linux netbsd openbsd sunos \
	unix-generic windows2000 windowsnt windowsserver2003 windowsxp \
	wrt54g
	${INSTALL_DATA} ${WRKSRC}/src/configs/default.${os} \
		${PREFIX}/osiris/configs
.endfor
	${CHOWN} -R osiris:osiris ${PREFIX}/osiris
	${INSTALL_PROGRAM} -m 4755 -o osiris -g osiris \
		${WRKSRC}/src/osirismd/osirismd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirismd.sh.sample \
		${PREFIX}/etc/rc.d
.endif

.include <bsd.port.post.mk>
