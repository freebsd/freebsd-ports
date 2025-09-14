PORTNAME=	smile
DISTVERSION=	2.10.2
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Emoji picker
WWW=		https://mijorus.it/projects/smile/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=1.2.18:devel/py-dbus@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig python \
		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	mijorus

USE_GNOME=	glib20 gtk40 libadwaita pygobject3
GLIB_SCHEMAS=	it.mijorus.smile.gschema.xml

SHEBANG_FILES=	src/smile.in
python_OLD_CMD=	@PYTHON@

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

OPTIONS_DEFAULT=	WAYLAND X11
OPTIONS_GROUP=		AUTOPASTE
OPTIONS_GROUP_AUTOPASTE=WAYLAND X11

AUTOPASTE_DESC=	Backend for automatic paste
WAYLAND_DESC=	Use wl-clipboard as backend on Wayland
X11_DESC=	Use xdotool as backend on X11

WAYLAND_RUN_DEPENDS=	wl-paste:x11/wl-clipboard
X11_RUN_DEPENDS=	xdotool:x11/xdotool

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type f \
		\( -name meson.build -o -name smile.in \) -delete

.include <bsd.port.mk>
