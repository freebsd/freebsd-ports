PORTNAME=	kaffeine
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia player based on VLC
WWW=		https://apps.kde.org/kaffeine/

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSES/CC0-1.0.txt

BUILD_DEPENDS=	v4l_compat>=1.18.0:multimedia/v4l_compat
LIB_DEPENDS=	libvlc.so:multimedia/vlc \
		libdvbv5.so:multimedia/libv4l

USES=		cmake cpe desktop-file-utils gettext inotify \
		pkgconfig kde:6 qt:6 tar:xz xorg
USE_KDE=	coreaddons dbusaddons i18n kio solid \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base svg
USE_XORG=	x11 xscrnsaver

CPE_VENDOR=	kaffeine
CPE_PRODUCT=	kaffeine_player

KDE_INVENT=	f5e0f38c625ab42ade837a8fc2ce6125c8104c1f

post-patch:
	@${RM} -r ${WRKSRC}/include

post-build:
	# Cleanup translated manpages, we don't want them
	${RM} ${STAGEDIR}/man/{ca,id,it,nl,pt,pt_BR,sv,uk}/man1/kaffeine.1.gz

.include <bsd.port.mk>
