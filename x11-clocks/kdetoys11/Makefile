# New ports collection makefile for:	kdetoys-i18n
# Version required:	1.1.1
# Date created:		18 may 1999
# Whom:			imura@cs.titech.ac.jp
#
# $Id$
#

DISTNAME=	kdetoys-1.1.1
PKGNAME=	kdetoys-i18n-1.1.1
CATEGORIES=	x11-clocks kde
MASTER_SITES=	http://apollon.cs.titech.ac.jp/~imura/kde-jp/po/
MASTER_SITES+=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.1/distribution/tar/generic/source/bz2
DISTFILES=	kdetoys-1.1.1.tar.bz2 \
		kdelnkfiles-ja-19990523.tar.bz2

MAINTAINER=     imura@cs.titech.ac.jp

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kfilei18n.2:${PORTSDIR}/x11/kdelibs11-i18n \
		qti18n.1:${PORTSDIR}/x11-toolkits/qt-i18n
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase11-i18n

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${DISTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	X_EXTRA_LIBS="-lxpg4"
CXXFLAGS?=	${CFLAGS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
CC=	egcc
CXX=	eg++
BUILD_DEPENDS= egcc:${PORTSDIR}/lang/egcs
.endif

.if defined(QT_GIF_AVAILABLE)
RESTRICTED=	requires Qt compiled with gif reading support
.else
BROKEN=		requires Qt compiled with gif reading support
.endif

.include <bsd.port.post.mk>
