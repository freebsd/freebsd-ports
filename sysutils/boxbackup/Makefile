# vim: ts=4
# New ports collection makefile for: boxbackup
# Date created:		19 December 2004
# Whom:				James O'Gorman <james@netinertia.co.uk>
#
# $FreeBSD$
#

PORTNAME=		boxbackup
PORTVERSION=	0.09
CATEGORIES=		sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(CLIENT_ONLY) && !defined(SERVER_ONLY)
PKGNAMESUFFIX=	-client
.elif defined(SERVER_ONLY) && !defined(CLIENT_ONLY)
PKGNAMESUFFIX=	-server
.endif
EXTRACT_SUFX=	.tgz

MAINTAINER=		james@netinertia.co.uk
COMMENT=		An open source, completely automatic on-line backup system for UNIX

USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	openssl:${OPENSSLBASE}
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
USE_PERL5=		yes

PKGMESSAGE=		${WRKDIR}/pkg-message

.if defined(CLIENT_ONLY) && !defined(SERVER_ONLY)
CONFLICTS=	boxbackup-[0-9]* boxbackup-server-[0-9]*
PLIST_SUB+=	CLIENT=""
PLIST_SUB+=	SERVER="@comment "
ALL_TARGET=	parcels/${DISTNAME}-backup-client-FreeBSD.tgz
INSTALL_TARGET=	install-backup-client
.elif defined(SERVER_ONLY) && !defined(CLIENT_ONLY)
CONFLICTS=	boxbackup-[0-9]* boxbackup-client-[0-9]*
PLIST_SUB+=	SERVER=""
PLIST_SUB+=	CLIENT="@comment "
ALL_TARGET=	parcels/${DISTNAME}-backup-server-FreeBSD.tgz
INSTALL_TARGET=	install-backup-server
.else
PLIST_SUB+=	CLIENT=""
PLIST_SUB+=	SERVER=""
INSTALL_TARGET=	install-backup-server install-backup-client
.endif

# These will be used at some point in the future when I get around to
# automating the final configuration.
#WITH_BACKUPSTORE?=	/var/bbstored
#WITH_WORKINGDIR?=	/var/bbackupd
#WITH_BACKUPMODE?=	lazy

.if ${.CURDIR} == ${MASTERDIR}
pre-everything::
	@${ECHO} "${PORTNAME} has the following options:"
	@${ECHO} ""
.if !defined(CLIENT_ONLY)
	@${ECHO} "  CLIENT_ONLY		Only install client suite"
.endif
.if !defined(SERVER_ONLY)
	@${ECHO} "  SERVER_ONLY		Only install server suite"
.endif
.if !defined(WITH_TESTS)
	@${ECHO} "  WITH_TESTS		Allows use of a \"check\" target"
	@${ECHO} "			to run tests"
.endif
	@${ECHO} ""
.if defined(SERVER_ONLY) && defined(CLIENT_ONLY)
	@${ECHO} "SERVER_ONLY and CLIENT_ONLY are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/infrastructure/BoxPlatform.pm
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/lib/common/BoxPortsAndFiles.h
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' <${FILESDIR}/bbstored.sh >\
		${WRKSRC}/bbstored.sh
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' <${FILESDIR}/bbackupd.sh >\
		${WRKSRC}/bbackupd.sh
	@${FIND} ${WRKSRC} -name "*.pl" -exec \
		${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' {} \;
	@${REINPLACE_CMD} -e 's, perl , ${PERL} ,' \
		${WRKSRC}/infrastructure/makebuildenv.pl
.if defined(CLIENT_ONLY) || !defined(SERVER_ONLY)
	@${CAT} ${FILESDIR}/pkg-message.client >> ${PKGMESSAGE}
.endif
.if defined(SERVER_ONLY) || !defined(CLIENT_ONLY)
	@${CAT} ${FILESDIR}/pkg-message.server >> ${PKGMESSAGE}
.endif

.if defined(SERVER_ONLY) || !defined(CLIENT_ONLY)
pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
	@${ECHO_CMD} "===> Installing startup scripts"
.if defined(CLIENT_ONLY) || !defined(SERVER_ONLY)
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/bbackupd.sh ${PREFIX}/etc/rc.d/bbackupd.sh
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbackupd
.endif
.if defined(SERVER_ONLY) || !defined(CLIENT_ONLY)
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/bbstored.sh ${PREFIX}/etc/rc.d/bbstored.sh
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbstored
.endif
	@${CAT} ${PKGMESSAGE}
# At some point we might want to automate final configuration...
#.if !defined(BATCH) && exists(${PREFIX}/bin/bbackupd-config)
#	@${PREFIX}/bin/bbackupd-config ${PREFIX}/etc/box ${WITH_BACKUPMODE} ${ACCOUNT} ${BACKUP_SERVER} ${WITH_WORKDIR} ${BACKUPDIRS}
#.endif

.if defined(WITH_TESTS)
check:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test
.endif

.include <bsd.port.mk>
