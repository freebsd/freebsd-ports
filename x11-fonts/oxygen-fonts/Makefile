PORTNAME=	oxygen-fonts
DISTVERSION=	5.4.3
CATEGORIES=	x11-fonts
MASTER_SITES=	KDE/Attic/plasma/${DISTVERSION}
DIST_SUBDIR=	KDE/plasma/${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Plasma5 Oxygen font family
WWW=		https://invent.kde.org/unmaintained/oxygen-fonts

LICENSE=	OFL11 GPLv3RLE+
LICENSE_COMB=	dual
LICENSE_FILE_OFL11=	${WRKSRC}/COPYING-OFL
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING-GPL+FE.txt

BUILD_DEPENDS=	fontforge:print/fontforge

USES=		cmake fonts:none kde qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base:build

# XXX variables not set in kf6-ecm
CMAKE_ARGS=	-DCMAKECONFIG_INSTALL_PREFIX=${QT_CMAKEDIR_REL} \
		-DSHARE_INSTALL_PREFIX=share

NO_ARCH=	yes

.include <bsd.port.mk>
