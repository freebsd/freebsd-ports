# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnumeric
PORTVERSION=	1.0.13
PORTREVISION=	1
CATEGORIES?=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	The GNOME spreadsheet

LIB_DEPENDS=	gnomeole2.0:${PORTSDIR}/devel/libole2 \
		gbrun.0:${PORTSDIR}/lang/gnomebasic \
		iconv.3:${PORTSDIR}/converters/libiconv \
		psiconv.8:${PORTSDIR}/converters/psiconv
RUN_DEPENDS=	guppi-gnumeric:${PORTSDIR}/math/guppi

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs bonobo libglade gal
USE_PYTHON=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-evolution --without-guile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lintl -liconv ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION=${PORTVERSION}-bonobo

post-install:
.for dir in share/gnome lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.mk>
