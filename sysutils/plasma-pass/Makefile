PORTNAME=	plasma-pass
DISTVERSION=	1.3.0
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for Pass password manager
WWW=		https://invent.kde.org/plasma/plasma-pass

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp  \
		liboath.so:security/oath-toolkit \
		libqgpgmeqt6.so:security/qgpgme@qt6
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++20-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	i18n itemmodels kio plasma5support \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
