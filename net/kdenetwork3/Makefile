# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	3.0
PORTREVISION=	1
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
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

UTMP=/var/run/utmp
.if exists(${UTMP})
PLIST_SUB+=	KTALKD=""
.else
PLIST_SUB+=	KTALKD="@comment "
pre-configure:
	@${ECHO_MSG} '===>  NOTE: The file ${UTMP} was not found.'
	@${ECHO_MSG} '===>  NOTE: ktalkd, which requires ${UTMP}, will not be built.'
.endif

.include <bsd.port.mk>
