# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	3.18.0
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME visual diff and merge tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext python:3.4+ shared-mime-info \
		shebangfix tar:xz
SHEBANG_FILES=	bin/meld
USE_PYTHON=	distutils noflavors
USE_GNOME=	gtksourceview3 intltool libxml2:build pygobject3
GLIB_SCHEMAS=	org.gnome.meld.gschema.xml
PYDISTUTILS_INSTALL_TARGET=	--no-update-icon-cache --no-compile-schemas install
INSTALLS_ICONS=	yes
NO_ARCH=	yes

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.post.mk>
