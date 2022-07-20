PORTNAME=	massxpert
DISTVERSION=	6.0.3
CATEGORIES=	science

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Software suite for (bio)chemists

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang gnome qt:5 xorg
USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org/
GL_ACCOUNT=	debichem-team
GL_COMMIT=	a21ad33eee0314df202146392023dfb3868b7d84
USE_GNOME=	glib20
USE_QT=		core gui printsupport svg widgets xml buildtools_build \
		qmake_build
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender

.include <bsd.port.mk>
