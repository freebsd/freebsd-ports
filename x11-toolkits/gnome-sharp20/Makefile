# Created by: Tom McLaughlin <tmclaugh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-sharp
PORTVERSION=	2.24.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME interfaces for the .NET runtime

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gmake gnome libtool mono pathfix perl5 pkgconfig \
		shebangfix tar:bzip2 xorg
USE_LDCONFIG=	yes
USE_GITHUB=	yes
USE_GNOME=	cairo gnomevfs2 gtksharp20 librsvg2 vte libgnomeprintui libgnomeui
USE_PERL5=	run
USE_XORG=	ice sm
SHEBANG_GLOB=	*.pl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GH_ACCOUNT=	mono

pre-configure:
	(cd ${WRKSRC}; ./bootstrap-2.24)

.include <bsd.port.mk>
