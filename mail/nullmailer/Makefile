# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
PORTVERSION=	1.05
PORTREVISION=	1
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

# Pass BATCH to pkg-install for Evil Things(tm)
# Pass LOCALSTATEDIR to pkg-install for creating home directory correctly
pre-install:
	@BATCH="${BATCH}" LOCALSTATEDIR="${LOCALSTATEDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@cd ${WRKSRC} && make install-root
	@${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${PREFIX}/etc/nullmailer/
	@BATCH="${BATCH}" NMH_PREFIX="${NMH_PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
