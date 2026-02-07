PORTNAME=	massxpert
DISTVERSION=	6.0.3
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software suite for (bio)chemists
WWW=		http://www.msxpertsuite.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang gnome qt:5 xorg
USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org/
GL_ACCOUNT=	debichem-team
GL_TAGNAME=	a21ad33eee0314df202146392023dfb3868b7d84
USE_GNOME=	glib20
USE_QT=		core gui printsupport svg widgets xml buildtools:build \
		qmake:build
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender

.include <bsd.port.mk>
