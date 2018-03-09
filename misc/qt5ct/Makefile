# $FreeBSD$

PORTNAME=	qt5ct
DISTVERSION=	0.35
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Qt 5 configuration tool

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

USES=		gettext-runtime qmake tar:bz2
USE_QT5=	core dbus gui svg widgets buildtools_build \
	linguisttools_build
USE_GL=	egl gl
USE_XORG=	x11 xext xrender
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR} && \
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
