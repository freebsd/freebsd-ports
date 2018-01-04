# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	font-manager
PORTVERSION=	0.5.7
PORTREVISION=	6
CATEGORIES=	x11-fonts gnome

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Font management application for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	FontManager
GH_PROJECT=	master

USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig python:2 tar:bzip2

PORTDATA=	*

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-runtime

pre-configure:
	@${CHMOD} 0544 ${WRKSRC}/configure ${WRKSRC}/po/pogen.sh

.include <bsd.port.mk>
