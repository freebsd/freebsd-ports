# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	1.90
CATEGORIES=	net news kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	unstable/distribution/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib \
		kdecore.4:${PORTSDIR}/x11/kdelibs2 \
		QwSpriteField.8:${PORTSDIR}/converters/kdesupport2

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_QT2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}"
USE_GMAKE=	yes

.include <bsd.port.mk>
