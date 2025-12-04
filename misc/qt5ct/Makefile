PORTNAME=	qt5ct
DISTVERSION=	1.8
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 configuration tool
WWW=		https://sourceforge.net/projects/qt5ct/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gettext-runtime gl gnome qt:5 \
		tar:bz2 xorg
USE_QT=		concurrent core dbus gui paths svg widgets \
		buildtools:build linguisttools:build qmake:build
USE_GL=		egl gl
USE_XORG=	x11 xext xrender
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR} && \
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
