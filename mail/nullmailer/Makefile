# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
# PORTVERSION=	1.00RC5
PORTVERSION=	1.00r5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/
# MASTER_SITE_SUBDIR=	${PORTVERSION}
MASTER_SITE_SUBDIR=	1.00RC5
DISTNAME=	${PORTNAME}-1.00RC5

MAINTAINER=	clive@FreeBSD.org

FORBIDDEN=	"A long standing bug is noted as a vulnerability on bugtraq"

HAS_CONFIGURE=	yes

CXXFLAGS+=	-lstdc++
MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8

PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(BATCH)
PLIST_SUB=		LOCALSTATEDIR="${PREFIX}"
PLIST_SUB+=		LOCALSTATEDIR_RM="@dirrm "
NMH_PREFIX=		${PREFIX}
.else
PLIST_SUB=		LOCALSTATEDIR=""
PLIST_SUB+=		LOCALSTATEDIR_RM="@comment "
CONFIGURE_ARGS+=	'--localstatedir=/var/'
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
