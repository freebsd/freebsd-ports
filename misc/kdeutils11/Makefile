# New ports collection makefile for:   kdeutils
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdeutils
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

PATCH_SITES=	http://www.kde.gr.jp/~asaki/KDE-1.1.2/SOURCES/
PATCHFILES=	kdeutils-ja.19991117.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-includes=$(PREFIX)/include
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" INSTALL_SCRIPT="install -c -m 555"
USE_GMAKE=	yes

.include <bsd.port.mk>
