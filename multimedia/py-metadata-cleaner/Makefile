PORTNAME=	metadata-cleaner
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	multimedia audio graphics python textproc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Python GTK application to view and clean metadata in files, using mat2
WWW=		https://gitlab.com/rmnvgr/metadata-cleaner

LICENSE=	CC-BY-SA-4.0 GPLv3+ OFL10
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSES/CC-BY-SA-4.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_OFL10=	${WRKSRC}/LICENSES/OFL-1.1.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR} \
		itstool:textproc/itstool
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig python shebangfix
USE_GITLAB=	yes
USE_GNOME=	gtk40 pygobject3 libadwaita
GLIB_SCHEMAS=	fr.romainvigier.MetadataCleaner.gschema.xml
USE_PYTHON=	concurrent flavors

SHEBANG_GLOB=	*.py *.py.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}
NO_ARCH=	yes
GL_ACCOUNT=	rmnvgr
GL_COMMIT=	62a400a96099d947502611a1b9bc67f7f48a675a

.include <bsd.port.mk>
