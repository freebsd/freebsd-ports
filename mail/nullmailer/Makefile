# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
# PORTVERSION=	1.00RC5
PORTVERSION=	1.00r5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		ftp://mirrors.dataloss.nl/mirrors/bgware/nullmailer/%SUBDIR%/
# MASTER_SITE_SUBDIR=	${PORTVERSION}
MASTER_SITE_SUBDIR=	1.00RC5
DISTNAME=	${PORTNAME}-1.00RC5

MAINTAINER=	clive@FreeBSD.org

HAS_CONFIGURE=	yes

CXXFLAGS+=	-lstdc++
MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8

PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(BATCH)
PLIST_SUB=		LOCALSTATEDIR="${PREFIX}"
PLIST_SUB+=		LOCALSTATEDIR_RM="@dirrm "
PLIST_SUB+=		SPOOL=""
NMH_PREFIX=		${PREFIX}
SPOOL=			spool/
.else
PLIST_SUB=		LOCALSTATEDIR=""
PLIST_SUB+=		LOCALSTATEDIR_RM="@comment "
PLIST_SUB+=		SPOOL="spool/"
CONFIGURE_ARGS+=	--localstatedir=/var/spool
#CONFIGURE_ARGS+=	--localstatedir=/var/spool --bindir='$${libexecdir}'/${PORTNAME} --sbindir='$${libexecdir}'/${PORTNAME}
.endif

# Pass BATCH to pkg-install for Evil Things(tm)
pre-install:
	@BATCH="${BATCH}" NMH_PREFIX="${NMH_PREFIX}" PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC} && make install && make install-root

post-install:
	@${INSTALL_SCRIPT} -c files/nullmail.sh ${PREFIX}/etc/rc.d/
	@${INSTALL_DATA} -c files/remotes.sample ${PREFIX}/etc/nullmailer/
	@${CAT} ${.CURDIR}/pkg-message | ${SED} -e 's,%%PREFIX%%,${PREFIX},' > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
