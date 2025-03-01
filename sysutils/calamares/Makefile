PORTNAME=	calamares
DISTVERSION=	3.3.14
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/calamares/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Distro- and desktop-independent installer
WWW=		https://calamares.io/

LICENSE=		BSD2CLAUSE CC-BY-4.0 CC0-1.0 GPLv3+ LGPL21 LGPL3+ MIT
LICENSE_COMB=		dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSES/BSD-2-Clause.txt
LICENSE_FILE_CC-BY-4.0=	${WRKSRC}/LICENSES/CC-BY-4.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSES/LGPL-3.0-or-later.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libyaml-cpp.so:devel/yaml-cpp \
		libpwquality.so:security/libpwquality \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		cmake compiler:c++17-lang cpe gettext kde:6 python qt:6
USE_KDE=	coreaddons dbusaddons \
		ecm:build
USE_QT=		base

CMAKE_OFF=	INSTALL_POLKIT

.include <bsd.port.mk>
