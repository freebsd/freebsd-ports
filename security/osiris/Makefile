# $FreeBSD$

PORTNAME=	osiris
PORTVERSION=	4.2.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shmoo client/server host integrity checker

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=	OSIRISMD OSIRISD PRINTDB CLI
OPTIONS_DEFAULT=	OSIRISD
OPTIONS_SUB=	yes

OSIRISMD_DESC=	Management daemon
OSIRISD_DESC=	Scan agent
PRINTDB_DESC=	Database print tool
CLI_DESC=	Management CLI

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	libreadline.so.6:devel/readline
.endif

post-build-PRINTDB-on:
	cd ${WRKSRC}/src/tools && ${MAKE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/osiris

do-install-CLI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/osiris ${STAGEDIR}${PREFIX}/sbin

do-install-PRINTDB-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/printdb ${STAGEDIR}${PREFIX}/bin

do-install-OSIRISD-on:
	${SED} -e 's|@INSTALLDIR@|${PREFIX}/sbin|g' \
		-e 's|@OSIRISDIR@|${PREFIX}/osiris|g' \
		${WRKSRC}/src/install/freebsd/osirisd.in > \
		${WRKSRC}/src/install/freebsd/osirisd.sh
	${INSTALL_PROGRAM} ${WRKSRC}/src/osirisd/osirisd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirisd.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d

do-install-OSIRISMD-on:
	${SED} -e 's|@INSTALLDIR@|${PREFIX}/sbin|g' \
		-e 's|@OSIRISDIR@|${PREFIX}/osiris|g' \
		${WRKSRC}/src/install/freebsd/osirismd.in > \
		${WRKSRC}/src/install/freebsd/osirismd.sh
	@${MKDIR} ${STAGEDIR}${PREFIX}/osiris/configs
.for os in aix bsdos darwin freebsd irix linux netbsd openbsd sunos \
	unix-generic windows2000 windowsnt windowsserver2003 windowsxp \
	wrt54g
	${INSTALL_DATA} ${WRKSRC}/src/configs/default.${os} \
		${STAGEDIR}${PREFIX}/osiris/configs
.endfor
	${INSTALL_PROGRAM} -m 4755 ${WRKSRC}/src/osirismd/osirismd \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/install/freebsd/osirismd.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
