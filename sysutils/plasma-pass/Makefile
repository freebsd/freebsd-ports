PORTNAME=	plasma-pass
DISTVERSION=	1.2.1
MASTER_SITES=	KDE/stable/${PORTNAME}
PORTREVISION=	3
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for Pass password manager
WWW=		https://github.com/kde/plasma-pass

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp  \
		liboath.so:security/oath-toolkit \
		libqgpgme.so:security/gpgme-qt@qt5
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n itemmodels package plasma-framework \
		service \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network \
		buildtools:build qmake:build

.include <bsd.port.mk>
