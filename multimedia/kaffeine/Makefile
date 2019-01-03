# Created by: arved
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	2.0.15
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia player based on KDE and VLC

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libvlc.so:multimedia/vlc \
		libdvbv5.so:multimedia/libv4l

USES=		cmake cpe desktop-file-utils gettext pkgconfig \
		kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n itemviews kio solid dbusaddons jobwidgets \
		service widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network phonon4 sql svg x11extras xml \
		widgets qmake_build buildtools_build
USE_XORG=	xscrnsaver

CPE_VENDOR=	kaffeine
CPE_PRODUCT=	kaffeine_player

post-build:
	# Cleanup translated manpages, we don't want them
	${RM} ${STAGEDIR}/man/{ca,id,it,nl,pt,pt_BR,sv,uk}/man1/kaffeine.1.gz

.include <bsd.port.mk>
