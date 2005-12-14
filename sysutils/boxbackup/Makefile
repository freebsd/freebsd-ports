# New ports collection makefile for: boxbackup
# Date created:		19 December 2004
# Whom:			James O'Gorman <james@netinertia.co.uk>
#
# $FreeBSD$
#

PORTNAME=	boxbackup
PORTVERSION=	0.09
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	james@netinertia.co.uk
COMMENT=	An open source, completely automatic on-line backup system for UNIX

USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	openssl:${OPENSSLBASE}
USE_REINPLACE=	yes
USE_PERL5=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	CLIENT "Install the bbackupd client" On \
		SERVER "Install the bbstored server" On \
		TESTS  "Allows use of a 'check' target to run tests" Off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least CLIENT or SERVER to be defined.\
		Please \`make config\` again
.endif

.if defined(WITHOUT_CLIENT)
PLIST_SUB+=	CLIENT="@comment "
.else
USE_RC_SUBR+=	bbackupd.sh
PLIST_SUB+=	CLIENT=""
ALL_TARGET+=	parcels/${DISTNAME}-backup-client-FreeBSD.tgz
INSTALL_TARGET+=install-backup-client
.endif

.if defined(WITHOUT_SERVER)
PLIST_SUB+=	SERVER="@comment "
.else
USE_RC_SUBR+=	bbstored.sh
PLIST_SUB+=	SERVER=""
ALL_TARGET+=	parcels/${DISTNAME}-backup-server-FreeBSD.tgz
INSTALL_TARGET+=install-backup-server
.endif

CONFLICTS=	boxbackup-server-[0-9]* boxbackup-client-[0-9]*
.if defined(WITHOUT_CLIENT)
CONFLICTS=	boxbackup[0-9]*
PKGNAMESUFFIX=	-server
.elif defined(WITHOUT_SERVER)
CONFLICTS=	boxbackup[0-9]*
PKGNAMESUFFIX=	-client
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/infrastructure/BoxPlatform.pm
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/lib/common/BoxPortsAndFiles.h
	@${FIND} ${WRKSRC} -name "*.pl" -exec \
		${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' {} \;
	@${REINPLACE_CMD} -e 's, perl , ${PERL} ,' \
		${WRKSRC}/infrastructure/makebuildenv.pl
.if !defined(WITHOUT_CLIENT)
	@${CAT} ${FILESDIR}/pkg-message.client >> ${PKGMESSAGE}
.endif
.if !defined(WITHOUT_SERVER)
	@${CAT} ${FILESDIR}/pkg-message.server >> ${PKGMESSAGE}
.endif

.if !defined(WITHOUT_SERVER)
pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
.if !defined(WITHOUT_CLIENT)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbackupd
.endif
.if !defined(WITHOUT_SERVER)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbstored
.endif
	@${CAT} ${PKGMESSAGE}

.if defined(WITH_TESTS)
check:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test
.endif

.include <bsd.port.post.mk>
