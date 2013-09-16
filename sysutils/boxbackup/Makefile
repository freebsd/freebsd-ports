# Created by: James O'Gorman <james@netinertia.co.uk>
# $FreeBSD$

PORTNAME=	boxbackup
PORTVERSION=	0.11.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	${CLIENT_OR_SERVER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	james@netinertia.co.uk
COMMENT=	Open source, completely automatic on-line backup system for Unix

LICENSE=	BSD GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-DUAL.txt

USES=		perl5
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal autoheader
ACLOCAL_ARGS+=	-I ${WRKSRC}/infrastructure/m4

MAKE_JOBS_UNSAFE=yes

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	READLINE

OPTIONS_MULTI=	FLAVOUR
OPTIONS_MULTI_FLAVOUR=	CLIENT SERVER

CLIENT_DESC=	Install the bbackupd client
SERVER_DESC=	Install the bbstored server

OPTIONS_DEFAULT=CLIENT SERVER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ARGS+=--enable-gnu-readline
.endif

MANCOMPRESSED=	yes
.if ${PORT_OPTIONS:MCLIENT}
USE_RC_SUBR+=	bbackupd
PLIST_SUB+=	CLIENT=""
SUB_LIST+=	CLIENT=""
ALL_TARGET+=	build-backup-client
INSTALL_TARGET+=install-backup-client
MAN5+=		bbackupd.conf.5
MAN8+=		bbackupd.8 bbackupctl.8 bbackupd-config.8 bbackupquery.8
SUB_FILES+=	999.boxbackup
.else
PLIST_SUB+=	CLIENT="@comment "
SUB_LIST+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR+=	bbstored
USERS+=		_bbstored
GROUPS+=	_bbstored
PLIST_SUB+=	SERVER=""
SUB_LIST+=	SERVER=""
ALL_TARGET+=	build-backup-server
INSTALL_TARGET+=install-backup-server
MAN5+=		bbstored.conf.5 raidfile.conf.5
MAN8+=		bbstored.8 bbstoreaccounts.8 bbstored-certs.8 bbstored-config.8 raidfile-config.8
.else
PLIST_SUB+=	SERVER="@comment "
SUB_LIST+=	SERVER="@comment "
.endif

.if ! ${PORT_OPTIONS:MCLIENT}
# if this is a server-only install, CONFLICT with an install of the CLIENT or both
CONFLICTS=	boxbackup-client-[0-9]* boxbackup-[0-9]*
CLIENT_OR_SERVER=-server
.elif ! ${PORT_OPTIONS:MSERVER}
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

post-configure:
	@${REINPLACE_CMD} -e '/share.doc.boxbackup/d' \
		${WRKSRC}/parcels/scripts/install-backup-*

post-install:
.if ${PORT_OPTIONS:MCLIENT}
	@${MKDIR} -m 0700 ${PREFIX}/etc/boxbackup/bbackupd
	@${MKDIR} ${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/999.boxbackup ${PREFIX}/etc/periodic/monthly
.endif
.if ${PORT_OPTIONS:MSERVER}
	@${MKDIR} -m 0700 ${PREFIX}/etc/boxbackup/bbstored
.endif
	@${CAT} ${PKGMESSAGE}

test:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
