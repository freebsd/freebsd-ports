# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
PORTEPOCH=	1
PORTVERSION=	1.03
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		http://untroubled.org/nullmailer/archive/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MTA for hosts which relay to a fixed set of smart relays

HAS_CONFIGURE=	yes

USE_SUBMAKE=	yes

MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8

USE_RC_SUBR=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

LOCALSTATEDIR=	/var/spool

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}
PLIST_SUB=		LOCALSTATEDIR=${LOCALSTATEDIR}
PKGINSTALL=		${WRKDIR}/pkg-install

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-extract:
	@${CAT} ${FILESDIR}/pkg-install.proto | ${SED} -e 's,%%LOCALSTATEDIR%%,${LOCALSTATEDIR},g' > ${WRKDIR}/pkg-install
	@${CAT} ${FILESDIR}/pkg-message.proto | ${SED} -e 's,%%PREFIX%%,${PREFIX},' > ${PKGMESSAGE}

# Pass BATCH to pkg-install for Evil Things(tm)
# Pass LOCALSTATEDIR to pkg-install for creating home directory correctly
pre-install:
	@BATCH="${BATCH}" LOCALSTATEDIR="${LOCALSTATEDIR}" PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@cd ${WRKSRC} && make install-root
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/nullmail.sh > ${WRKDIR}/nullmail.sh
	@${INSTALL_SCRIPT} -c ${WRKDIR}/nullmail.sh ${PREFIX}/etc/rc.d/
	@${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${PREFIX}/etc/nullmailer/
	@BATCH="${BATCH}" NMH_PREFIX="${NMH_PREFIX}" PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
