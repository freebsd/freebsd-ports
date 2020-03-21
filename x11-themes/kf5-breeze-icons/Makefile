# $FreeBSD$

PORTNAME=	breeze-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Breeze icon theme for KDE

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING-ICONS

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cmake kde:5 qt:5 shebangfix tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build core qmake_build testlib

SHEBANG_FILES=	generate-24px-versions.sh

NO_ARCH=	yes

.include <bsd.port.mk>
