PORTNAME=	metadata-cleaner
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
CATEGORIES=	multimedia audio graphics python textproc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MASTER_SITES=	https://gitlab.com/rmnvgr/metadata-cleaner/-/archive/v${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	Python GTK application to view and clean metadata in files, using mat2

LICENSE=	CC-BY-SA-4.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSES/CC-BY-SA-4.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR} \
		itstool:textproc/itstool
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR}

USES=		gettext-tools gnome meson pkgconfig python shebangfix tar:bz2
USE_GNOME=	gtk40 pygobject3 libadwaita
GLIB_SCHEMAS=	fr.romainvigier.MetadataCleaner.gschema.xml
USE_PYTHON=	concurrent flavors

SHEBANG_GLOB=	*.py *.py.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
