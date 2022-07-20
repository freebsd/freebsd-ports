PORTNAME=	shared-mime-info
DISTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	misc gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	MIME types database from the freedesktop.org project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gmake:devel/gmake \
		minixmlto:textproc/minixmlto

USES=		gettext gnome localbase meson pathfix pkgconfig python:build shebangfix \
		tar:xz trigger
CONFIGURE_ARGS=	-Dupdate-mimedb=false \
		-Dxdgmime-path=${WRKSRC}/src/xdgmime
USE_GNOME=	glib20 libxml2
USE_GITLAB=	YES
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	xdg
GL_PROJECT=	shared-mime-info
GL_COMMIT=	13695c7225c2f525a435e72739c33ac32bbfbbb9
GL_TUPLE=	xdg:xdgmime:de283fc430460b9b3a7e61432a6d273cd64cb102:xdgmime/src/xdgmime
bash_CMD=	/bin/sh
SHEBANG_FILES=	${WRKSRC}/tests/compare_iana.py \
		${WRKSRC}/tests/mime-detection/pyside.py \
		${WRKSRC}/tests/mime-detection/pyside.py \
		${WRKSRC}/tests/mime-detection/test.py \
		${WRKSRC}/tests/mime-detection/test.py3 \
		${WRKSRC}/tests/mime-detection/test3.py \
		${WRKSRC}/tests/test_case.py \
		${WRKSRC}/tests/test_sub_class_ofs.py

MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video x-epoc x-content font

BINARY_ALIAS=	xmlto=minixmlto

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/xdgmime/src/xdgmime.c \
		${WRKSRC}/src/update-mime-database.c
	${REINPLACE_CMD} 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${WRKSRC}/data/freedesktop.org.xml.in

pre-configure:
	cd ${WRKSRC}/src/xdgmime/src && ${SETENV} ${MAKE_ENV} ${GMAKE}

post-install:
	for dir in ${MIMESUBDIRS} ; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/$${dir} ; \
	done

.include <bsd.port.mk>
