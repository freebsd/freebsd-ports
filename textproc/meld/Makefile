PORTNAME=	meld
DISTVERSION=	3.22.3
PORTEPOCH=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME visual diff and merge tool
WWW=		https://meld.app/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gnome meson pkgconfig python shared-mime-info \
		shebangfix tar:xz
USE_GNOME=	gtksourceview4 intltool libxml2:build pygobject3

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

MESON_ARGS=	-Dbyte-compile=false
SHEBANG_FILES=	bin/meld
BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.meld.gschema.xml
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|dependency('python3'|dependency('python-${PYTHON_VER}'|" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
