# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	3.16.1
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME visual diff and merge tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext python:2 shared-mime-info \
		shebangfix tar:xz
SHEBANG_FILES=	bin/meld
USE_PYTHON=	distutils
USE_GNOME=	gtksourceview3 pygobject3 intltool
GLIB_SCHEMAS=	org.gnome.meld.gschema.xml
PYDISTUTILS_INSTALLNOSINGLE=	yes
PYDISTUTILS_INSTALL_TARGET=	--no-update-icon-cache --no-compile-schemas install
INSTALLS_ICONS=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
