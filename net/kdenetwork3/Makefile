# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	2.2.1
CATEGORIES?=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s:-lpthread:${PTHREAD_LIBS}:g" ${WRKSRC}/knode/Makefile.in
	${PERL} -pi -e "s@all_includes=\"@all_includes=\"-I/usr/include @g" ${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4
	${PERL} -pi -e "s@^AC_CHECK_UTMP_FILE@# AC_CHECK_UTMP_FILE@g" ${WRKSRC}/configure.in

.include <bsd.port.mk>
