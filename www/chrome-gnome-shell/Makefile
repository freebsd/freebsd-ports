PORTNAME=	chrome-gnome-shell
DISTVERSION=	10.1
PORTREVISION=	4
CATEGORIES=	www gnome
MASTER_SITES=	https://download.gnome.org/sources/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	daniel@shafer.cc
COMMENT=	GNOME Shell integration for Chrome
WWW=		https://wiki.gnome.org/Projects/GnomeShellIntegrationForChrome

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		base64:converters/base64 \
		gnome-shell>=3.28:x11/gnome-shell \
		jq:textproc/jq

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		gnome-shell>=3.28:x11/gnome-shell \
		unzip>=6.0:archivers/unzip

USES=		cmake gnome python tar:xz
USE_GNOME=	pygobject3

CMAKE_OFF=	BUILD_EXTENSION
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=lib

INSTALL_TARGET=	install

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/find_program_ex/s|gsha256sum|gsha256sum sha256|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
