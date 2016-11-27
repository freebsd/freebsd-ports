# Created by: Tom McLaughlin <tmclaugh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-sharp
PORTVERSION=	2.24.2
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME interfaces for the .NET runtime

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gettext-runtime gmake libtool mono pathfix perl5 pkgconfig shebangfix tar:bzip2
USE_GNOME=	cairo gnomevfs2 gtksharp20 librsvg2 vte libgnomeprintui libgnomeui
USE_PERL5=	run
USE_XORG=	ice sm
INSTALL_TARGET=	install-strip
SHEBANG_GLOB=	*.pl

.include <bsd.port.mk>
