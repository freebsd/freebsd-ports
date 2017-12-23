# Created by: James O'Gorman <james@netinertia.co.uk>
# $FreeBSD$

PORTNAME=	boxbackup
PORTVERSION=	0.11.r${SVNVERSION:C/^[0-9\.]+_[a-z]+_([0-9]+)/\1/}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.boxbackup.org/snapshots/201108/
PKGNAMESUFFIX=	${CLIENT_OR_SERVER}-devel
DISTNAME=	${PORTNAME}-${SVNVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Open source, completely automatic on-line backup system for UNIX

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-DUAL.txt

SVNVERSION=	0.11_trunk_2979

USES=		autoreconf perl5 ssl tar:tgz
GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_MULTI=	TYPE
OPTIONS_MULTI_TYPE=	CLIENT SERVER
OPTIONS_DEFINE=	GNUREADLINE
OPTIONS_DEFAULT=	CLIENT SERVER
CLIENT_DESC=		Install the bbackupd client
SERVER_DESC=		Install the bbstored server
GNUREADLINE_DESC=	Enable the use of GNU readline

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

CLIENTDIR=	CLIENT
SERVERDIR=	SERVER
CLIENT_FILES=	bbackupd bbackupquery bbackupctl
SERVER_FILES=	bbstored bbstoreaccounts

.if ${PORT_OPTIONS:MGNUREADLINE}
CONFIGURE_ARGS+=--enable-gnu-readline
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_RC_SUBR+=	bbackupd
PLIST_SUB+=	CLIENT=""
ALL_TARGET+=	build-backup-client
CLIENT_SCRIPTS=	bbackupd-config
SUB_FILES+=	999.boxbackup
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR+=	bbstored
USERS+=		_bbstored
GROUPS+=	_bbstored
PLIST_SUB+=	SERVER=""
ALL_TARGET+=	build-backup-server
SERVER_SCRIPTS=	bbstored-certs bbstored-config raidfile-config
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if ! ${PORT_OPTIONS:MCLIENT}
CONFLICTS=	boxbackup-client-[0-9]* boxbackup-[0-9]*
CLIENT_OR_SERVER=-server
.elif ! ${PORT_OPTIONS:MSERVER}
CONFLICTS=	boxbackup-server-[0-9]* boxbackup-[0-9]*
CLIENT_OR_SERVER=-client
.else
CONFLICTS=	boxbackup-server-[0-9]* boxbackup-client-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/html/d' ${WRKSRC}/parcels.txt
.if ${PORT_OPTIONS:MCLIENT}
	@${CAT} ${FILESDIR}/pkg-message.client >> ${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MSERVER}
	@${CAT} ${FILESDIR}/pkg-message.server >> ${PKGMESSAGE}
.endif

post-configure:
	@${REINPLACE_CMD} -e '/share.doc.boxbackup/d' ${WRKSRC}/parcels/scripts/install-backup-*
pre-install:
	(cd ${WRKSRC}/parcels \
	&& ${MV} ./boxbackup-0.11_trunk_2979-backup-client ../CLIENT)

	(cd ${WRKSRC}/parcels \
	&& ${MV} ./boxbackup-0.11_trunk_2979-backup-server ../SERVER)
do-install:
.if ${PORT_OPTIONS:MCLIENT}
	(cd ${WRKSRC}/${CLIENTDIR}/ \
	&& ${INSTALL_PROGRAM} ${CLIENT_FILES} ${STAGEDIR}${PREFIX}/sbin/)

	(cd ${WRKSRC}/${CLIENTDIR}/ \
	&& ${INSTALL_SCRIPT} ${CLIENT_SCRIPTS} ${STAGEDIR}${PREFIX}/sbin/)

	${INSTALL_MAN} ${WRKSRC}/${CLIENTDIR}/bbackupd.conf.5.gz \
	${STAGEDIR}${PREFIX}/man/man5/

	${INSTALL_MAN} ${WRKSRC}/${CLIENTDIR}/bbackupctl.8.gz \
	${WRKSRC}/${CLIENTDIR}/bbackupd-config.8.gz \
	${WRKSRC}/${CLIENTDIR}/bbackupd.8.gz ${WRKSRC}/${CLIENTDIR}/bbackupquery.8.gz \
	${STAGEDIR}${PREFIX}/man/man8/
.endif
.if ${PORT_OPTIONS:MSERVER}
	(cd ${WRKSRC}/${SERVERDIR}/ \
	&& ${INSTALL_PROGRAM} ${SERVER_FILES} ${STAGEDIR}${PREFIX}/sbin/)

	(cd ${WRKSRC}/${SERVERDIR}/ \
	&& ${INSTALL_SCRIPT} ${SERVER_SCRIPTS} ${STAGEDIR}${PREFIX}/sbin/)

	${INSTALL_MAN} ${WRKSRC}/${SERVERDIR}/raidfile.conf.5.gz \
	${WRKSRC}/${SERVERDIR}/bbstored.conf.5.gz \
	${STAGEDIR}${PREFIX}/man/man5/

	${INSTALL_MAN} ${WRKSRC}/${SERVERDIR}/bbstoreaccounts.8.gz \
	${WRKSRC}/${SERVERDIR}/bbstored-certs.8.gz \
	${WRKSRC}/${SERVERDIR}/bbstored-config.8.gz \
	${WRKSRC}/${SERVERDIR}/bbstored.8.gz \
	${WRKSRC}/${SERVERDIR}/raidfile-config.8.gz \
	${STAGEDIR}${PREFIX}/man/man8/
.endif
.if ${PORT_OPTIONS:MCLIENT}
	@${MKDIR} -m 0700 ${STAGEDIR}${PREFIX}/etc/box/bbackupd
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/999.boxbackup ${STAGEDIR}${PREFIX}/etc/periodic/monthly
.endif
.if ${PORT_OPTIONS:MSERVER}
	@${MKDIR} -m 0700 ${STAGEDIR}${PREFIX}/etc/box/bbstored
.endif

test:
	 @${ECHO_CMD} "===> Running tests"
	 @${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
