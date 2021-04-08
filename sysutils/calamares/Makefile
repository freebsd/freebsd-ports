PORTNAME=	calamares
DISTVERSION=	3.2.44.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/calamares/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Distro- and desktop-independent installer

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libyaml-cpp.so:devel/yaml-cpp \
		libpwquality.so:security/libpwquality \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		cmake compiler:c++17-lang cpe gettext kde:5 python qt:5
USE_KDE=	coreaddons dbusaddons \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		svg widgets xml \
		buildtools_build qmake_build

CMAKE_OFF=	INSTALL_POLKIT
		
.include <bsd.port.mk>
