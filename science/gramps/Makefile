PORTNAME=	gramps
DISTVERSION=	6.0.4
CATEGORIES=	science gnome python
MASTER_SITES=	PYPI

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	GTK3-based genealogy program
WWW=		https://gramps-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgeocode-glib.so:net/geocode-glib \
		libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}berkeleydb>0:databases/py-berkeleydb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygraphviz>=0:graphics/py-pygraphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=1.8:devel/py-pyicu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		desktop-file-utils gettext gnome python shared-mime-info
USE_GNOME=	cairo gtk30 intltool librsvg2 pango pygobject3
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		GEXIV GTKSPELL PIL RCS TTFFREEFONT
OPTIONS_DEFAULT=	GEXIV GTKSPELL
GEXIV_DESC=		Manage Exif metadata embedded in media
GTKSPELL_DESC=		Spell checking support via gtkspell
PIL_DESC=		Crop/convert images with Python Imaging Library (Pillow)
RCS_DESC=		Manage revisions of family trees with with GNU RCS
TTFFREEFONT_DESC=	More font support in reports

GEXIV_LIB_DEPENDS=		libgexiv2.so:graphics/gexiv2
GTKSPELL_LIB_DEPENDS=		libgtkspell3-3.so:textproc/gtkspell3
PIL_RUN_DEPENDS=		${PY_PILLOW}
RCS_RUN_DEPENDS=		rcsdiff:devel/rcs
TTFFREEFONT_RUN_DEPENDS=	${LOCALBASE}/share/fonts/freefont-ttf/FreeMono.ttf:x11-fonts/freefont-ttf

.include <bsd.port.mk>
