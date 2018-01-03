# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	4.2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	science gnome python

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK3-based genealogy program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb3>0:databases/py-bsddb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=1.8:devel/py-pyicu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygraphviz>=0:graphics/py-pygraphviz@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils

USE_GITHUB=	yes
GH_ACCOUNT=	gramps-project

NO_ARCH=	yes
USES=		desktop-file-utils gettext shared-mime-info python:3.2+
USE_GNOME=	cairo gtk30 intltool librsvg2 pango pygobject3
USE_PYTHON=	autoplist distutils optsuffix
CONFIGURE_ARGS=	--disable-mime-install
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		GEXIV GTKSPELL PIL RCS TTFFREEFONT
OPTIONS_DEFAULT=	GEXIV GTKSPELL
GEXIV_DESC=		Manage Exif metadata embedded in media
GTKSPELL_DESC=		Spell checking support via gtkspell
PIL_DESC=		Crop/convert images with Python Imaging Library (Pillow)
RCS_DESC=		Manage revisions of family trees with with GNU RCS
TTFFREEFONT_DESC=	More font support in reports

GEXIV_LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2
GTKSPELL_LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3
PIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
RCS_RUN_DEPENDS=	rcsdiff:devel/rcs
TTFFREEFONT_RUN_DEPENDS=${LOCALBASE}/share/fonts/freefont-ttf/FreeMono.ttf:x11-fonts/freefont-ttf

post-install:
	${ECHO_CMD} -n ${PREFIX}/share > ${STAGEDIR}${PYTHON_SITELIBDIR}/gramps/gen/utils/resource-path

.include <bsd.port.mk>
