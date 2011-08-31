# New ports collection makefile for: boxbackup
# Date created:		19 December 2004
# Whom:			James O'Gorman <james@netinertia.co.uk>
#
# $FreeBSD$
#

PORTNAME=	boxbackup
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	${CLIENT_OR_SERVER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	james@netinertia.co.uk
COMMENT=	Open source, completely automatic on-line backup system for Unix

LICENSE=	BSD GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-DUAL.txt

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	autoconf aclocal autoheader
ACLOCAL_ARGS+=	-I ${WRKSRC}/infrastructure/m4

MAKE_JOBS_UNSAFE=yes

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	CLIENT "Install the bbackupd client" On \
		SERVER "Install the bbstored server" On \
		GNUREADLINE "Enable the use of GNU readline" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GNUREADLINE)
CONFIGURE_ARGS+=--enable-gnu-readline
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least CLIENT or SERVER to be defined.\
		Please 'make config' again
.endif

MANCOMPRESSED=	yes
.if defined(WITH_CLIENT)
USE_RC_SUBR+=	bbackupd
PLIST_SUB+=	CLIENT=""
ALL_TARGET+=	build-backup-client
INSTALL_TARGET+=install-backup-client
MAN5+=		bbackupd.conf.5
MAN8+=		bbackupd.8 bbackupctl.8 bbackupd-config.8 bbackupquery.8
SUB_FILES+=	999.boxbackup
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_SERVER)
USE_RC_SUBR+=	bbstored
USERS+=		_bbstored
GROUPS+=	_bbstored
PLIST_SUB+=	SERVER=""
ALL_TARGET+=	build-backup-server
INSTALL_TARGET+=install-backup-server
MAN5+=		bbstored.conf.5 raidfile.conf.5
MAN8+=		bbstored.8 bbstoreaccounts.8 bbstored-certs.8 bbstored-config.8 raidfile-config.8
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if defined(WITHOUT_CLIENT)
# if this is a server-only install, CONFLICT with an install of the CLIENT or both
CONFLICTS=	boxbackup-client-[0-9]* boxbackup-[0-9]*
CLIENT_OR_SERVER=-server
.elif defined(WITHOUT_SERVER)
# if this is a client-only install, CONFLICT with an install of the SERVER or both
CONFLICTS=	boxbackup-server-[0-9]* boxbackup-[0-9]*
CLIENT_OR_SERVER=-client
.else
# if we install boxbackup-[0-9]*, we should CONFLICT with a CLIENT or SERVER only install
# PKGNAMESUFFIX is empty at this point
CONFLICTS=	boxbackup-server-[0-9]* boxbackup-client-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/html/d' ${WRKSRC}/parcels.txt
.if !defined(WITHOUT_CLIENT)
	@${CAT} ${FILESDIR}/pkg-message.client >> ${PKGMESSAGE}
.endif
.if !defined(WITHOUT_SERVER)
	@${CAT} ${FILESDIR}/pkg-message.server >> ${PKGMESSAGE}
.endif

post-configure:
	@${REINPLACE_CMD} -e '/share.doc.boxbackup/d' ${WRKSRC}/parcels/scripts/install-backup-*

post-install:
.if !defined(WITHOUT_CLIENT)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbackupd
	@${MKDIR} ${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/999.boxbackup ${PREFIX}/etc/periodic/monthly
.endif
.if !defined(WITHOUT_SERVER)
	@${MKDIR} -m 0700 ${PREFIX}/etc/box/bbstored
.endif
	@${CAT} ${PKGMESSAGE}

test:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
