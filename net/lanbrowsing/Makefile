# New ports collection makefile for:	lanbrowsing
# Date created:				September 02 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lanbrowsing
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdenetwork-
DISTNAME=	kdenetwork-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lanbrowsing facility and backend for KDE

RUN_DEPENDS=	nmblookup:${PORTSDIR}/net/samba3

CONFLICTS=	kdenetwork-3.3.0

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_RC_SUBR=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdenetwork-${PORTVERSION}
INSTALLS_SHLIB=	yes

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
	${ECHO_CMD} ${PORTNAME} doc > ${WRKSRC}/inst-apps
	${REINPLACE_CMD} \
	's|^SUBDIRS =.*lisa.*$$|SUBDIRS =\. lisa|g' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/lanbrowsing/kcmlisa/main.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/kcmlisa.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/setupwizard.cpp

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/lisa.sh > ${PREFIX}/etc/rc.d/lisa.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/lisa.sh

.include <bsd.port.post.mk>
