# $FreeBSD$

PORTNAME=	pageedit
PORTVERSION=	1.2.0
CATEGORIES=	textproc

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	WYSIWYG visual XHTML editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

DEPRECATED=	Uses EOL Python 2.7 via www/qt5-webengine
EXPIRATION_DATE=2021-06-23

USES=		cmake qt:5 desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	PageEdit

USE_QT=		concurrent core declarative gui location network \
		printsupport webchannel webengine widgets xml \
		buildtools_build linguisttools_build qmake_build

.include <bsd.port.mk>
