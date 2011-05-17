# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
PORTVERSION=	1.05
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		http://untroubled.org/nullmailer/archive/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	MTA for hosts which relay to a fixed set of smart relays

LOCALSTATEDIR=	/var/spool

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		nullmail
GROUPS=		nullmail
NULLMAIL_UID=	522
NULLMAIL_GID=	522

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

USE_SUBMAKE=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-install pkg-deinstall pkg-message

PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	LOCALSTATEDIR=${LOCALSTATEDIR}
SUB_LIST+=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}

MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8

post-install:
	@cd ${WRKSRC} && make install-data install-root

# Append commands that reference the nullmailer user to the plist, because
# we need to ensure that the account has been created by bsd.port.mk by
# the time these are executed.
	@${ECHO_CMD} '@exec ${PW} usermod ${USERS} -d ${LOCALSTATEDIR}/nullmailer' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} ${USERS}:${USERS} ${LOCALSTATEDIR}/nullmailer/queue' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} ${USERS}:${USERS} ${LOCALSTATEDIR}/nullmailer/tmp' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} ${USERS}:${USERS} ${LOCALSTATEDIR}/nullmailer/trigger' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} ${USERS} ${PREFIX}/sbin/nullmailer-queue' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} ${USERS} ${PREFIX}/libexec/nullmailer/mailq' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${USERS} ${LOCALSTATEDIR}/nullmailer' >> ${TMPPLIST}

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${PREFIX}/etc/nullmailer/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
