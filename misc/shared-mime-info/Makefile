PORTNAME=	shared-mime-info
DISTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	misc gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	MIME types database from the freedesktop.org project
WWW=		https://www.freedesktop.org/wiki/Software/shared-mime-info/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome localbase meson pathfix pkgconfig python:build shebangfix \
		tar:xz trigger
CONFIGURE_ARGS=	-Dupdate-mimedb=false \
		-Dxdgmime-path=${WRKSRC}/src/xdgmime
USE_GNOME=	glib20 libxml2
USE_GITLAB=	YES
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	xdg
GL_TUPLE=	xdg:xdgmime:e861d3eb3d522a9c22c5a870526728e2a3d9fc04:xdgmime/src/xdgmime
bash_CMD=	/bin/sh
SHEBANG_FILES=	${WRKSRC}/tests/*.py \
		${WRKSRC}/tests/mime-detection/*.py \
		${WRKSRC}/tests/*.sh \
		${WRKSRC}/po/check_translations.sh

# these come from update-mime-database.cpp:const char *media_types[]
MIMESUBDIRS=	all application audio chemical font image inode message model \
		multipart print text uri video x-content x-epoc x-scheme-handler

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/xdgmime/src/xdgmime.c \
		${WRKSRC}/src/update-mime-database.cpp
	${REINPLACE_CMD} 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${WRKSRC}/data/freedesktop.org.xml.in

post-install:
	for dir in ${MIMESUBDIRS} ; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/$${dir} ; \
	done

.include <bsd.port.mk>
