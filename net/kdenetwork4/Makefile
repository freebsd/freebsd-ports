# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	3.0.5
CATEGORIES?=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

USE_KDEBASE_VER=3
USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.if ${MACHINE_ARCH} == "alpha"
_NO_KDE_FINAL= yes
.endif

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

UTMP?=	/var/run/utmp
.if exists(${UTMP})
PLIST_SUB+=	KTALKD=""
.else
PLIST_SUB+=	KTALKD="@comment "
pre-configure:
	@${ECHO_MSG} '===>  NOTE: The file ${UTMP} was not found.'
	@${ECHO_MSG} '===>  NOTE: ktalkd and kotalkd, which require ${UTMP}, will not be built.'
.endif

post-patch:
# XXX - remove at next port update
	@${REINPLACE_CMD} -e 's|\$$KDEDIR|${PREFIX}|' \
		${WRKSRC}/knewsticker/knewsticker-standalone.desktop

.include <bsd.port.mk>
