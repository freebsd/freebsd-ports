# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	shared-mime-info
DISTVERSION=	2.0
CATEGORIES=	misc gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	MIME types database from the freedesktop.org project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gmake:devel/gmake \
		itstool:textproc/itstool \
		minixmlto:textproc/minixmlto

USES=		gettext gnome localbase meson pathfix pkgconfig shebangfix tar:xz
CONFIGURE_ARGS=	-Dupdate-mimedb=false \
		-Dxdgmime-path=${WRKSRC}/src/xdgmime
USE_GNOME=	glib20 libxml2
USE_GITLAB=	YES
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	xdg
GL_PROJECT=	shared-mime-info
GL_COMMIT=	ef58b2b2f7ad4070171c6e45e3b3764daa3ff2c1
GL_TUPLE=	xdg:xdgmime:6663a2288d11b37bc07f5a01b4b85dcd377787e1:xdgmime/src/xdgmime
bash_CMD=	/bin/sh
SHEBANG_FILES=	${WRKSRC}/data/freedesktop_generate.sh

SUB_FILES=	pkg-install
SUB_LIST=	MIMEDIRS="${MIMEDIRS:O:u}"

MIMEDIRS=	${LOCALBASE}/share/mime \
		${PREFIX}/share/mime
MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video x-epoc x-content

BINARY_ALIAS=	xmlto=minixmlto

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/xdgmime/src/xdgmime.c \
		${WRKSRC}/src/update-mime-database.c

pre-configure:
	cd ${WRKSRC}/src/xdgmime/src && ${SETENV} ${MAKE_ENV} ${GMAKE}

.include <bsd.port.mk>
