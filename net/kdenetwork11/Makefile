# New ports collection makefile for:   kdenetwork
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

PATCH_SITES=	http://www.kde.gr.jp/~toyohiro/ \
		http://www.kde.gr.jp/~imura/ko/
PATCHFILES=	kdenetwork-1.1.2-ja-19991124.diff.gz \
		kdenetwork-1.1.2-ko-20000108.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm \
		msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		QwSpriteField.7:${PORTSDIR}/converters/kdesupport11
		
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" INSTALL_SCRIPT="install -c -m 555" \
		QTDIR=${QTDIR} \
		DO_NOT_COMPILE=ksirc
USE_GMAKE=	yes
CFLAGS+=	"-I${PREFIX}/include"

.if defined(PREFIX)
QTDIR?=		${PREFIX}
.else
QTDIR?=		${X11BASE}
.endif

.include <bsd.port.mk>
