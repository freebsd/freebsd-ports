# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	3.0.1
CATEGORIES?=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

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

.include <bsd.port.mk>
