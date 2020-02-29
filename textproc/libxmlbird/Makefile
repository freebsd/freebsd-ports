# $FreeBSD$

PORTNAME=	libxmlbird
DISTVERSION=	1.2.11
CATEGORIES=	textproc devel
MASTER_SITES=	https://birdfont.org/xmlbird-releases/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	XML parser for Vala and C programs

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}doit>0:devel/py-doit@${PY_FLAVOR} \
		valac:lang/vala

USES=		gettext-runtime gnome pkgconfig python:3.7+,build shebangfix tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
SHEBANG_FILES=	configure install.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" \
		--cflags="${CFLAGS}" \
		--dest="${STAGEDIR}" \
		--ldflags="${LDFLAGS}" \
		--prefix="${PREFIX}"

PLIST_FILES=	include/xmlbird.h \
		lib/libxmlbird.so \
		lib/libxmlbird.so.1 \
		libdata/pkgconfig/xmlbird.pc \
		share/vala/vapi/xmlbird.vapi

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/doit)

do-install:
	(cd ${WRKSRC} && ./install.py --dest="${STAGEDIR}")
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxmlbird.so.1

.include <bsd.port.mk>
