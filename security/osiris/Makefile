# New ports collection Makefile for: 	osiris
# Date created:				10, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	osiris
PORTVERSION=	4.0.6
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The Shmoo client/server host integrity checker

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15

.if defined(WITH_OSIRISMD)
PLIST_SUB+=	OSIRISMD=""
.else
PLIST_SUB+=	OSIRISMD="@comment "
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_OSIRISMD to enable build of the management daemon."
	@${ECHO_MSG}

post-build:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/install/freebsd/osirisd.in > \
		${WRKSRC}/src/install/freebsd/osirisd.sh.sample
.if defined(WITH_OSIRISMD)
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/install/freebsd/osirismd.in > \
		${WRKSRC}/src/install/freebsd/osirismd.sh.sample
.endif

do-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/osiris/configs
.for os in aix bsdos darwin freebsd irix linux openbsd sunos unix-generic \
	windows2000 windowsnt windowsserver2003 windowsxp
	${INSTALL_DATA} ${WRKSRC}/src/configs/default.${os} \
		${PREFIX}/osiris/configs
.endfor
	${CHOWN} -R osiris:osiris ${PREFIX}/osiris
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/osiris ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirisd/osirisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirisd.sh.sample \
		${PREFIX}/etc/rc.d
.if defined(WITH_OSIRISMD)
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirismd/osirismd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirismd.sh.sample \
		${PREFIX}/etc/rc.d
.endif

.include <bsd.port.mk>
