# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES?=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
BUILD_DEPENDS+=	objprelink:${PORTSDIR}/devel/objprelink
.endif
LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
CONFIGURE_ARGS+=--enable-objprelink
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
STRIP=''
.endif
USE_GMAKE=	yes
CONFIGURE_ENV+=	PATH=${WRKSRC}/auto-bin:$$PATH
MAKE_ENV=	${CONFIGURE_ENV}

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	${PERL} -pi -e "s:-lpthread:${PTHREAD_LIBS}:g" ${WRKSRC}/knode/Makefile.in
	${PERL} -pi -e "s@all_includes=\"@all_includes=\"-I/usr/include @g" ${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4
	${PERL} -pi -e "s@^AC_CHECK_UTMP_FILE@# AC_CHECK_UTMP_FILE@g" ${WRKSRC}/configure.in

.include <bsd.port.mk>
