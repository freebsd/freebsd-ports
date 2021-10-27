PORTNAME=	metadata-cleaner
DISTVERSION=	1.0.7
CATEGORIES=	multimedia audio graphics python textproc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@fuz.su
COMMENT=	Python GTK application to view and clean metadata in files, using mat2

LICENSE=	CC-BY-SA-4.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSES/CC-BY-SA-4.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR}
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mat2>0:multimedia/py-mat2@${PY_FLAVOR}

USES=		gettext-tools gnome meson pkgconfig python shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	rmnvgr
GL_COMMIT=	b8cd4f28c82d5da9b93cd892355b66f8b7340129
USE_GNOME=	gtk30 pygobject3
GLIB_SCHEMAS=	fr.romainvigier.MetadataCleaner.gschema.xml
USE_PYTHON=	concurrent flavors

SHEBANG_GLOB=	*.py *.py.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
