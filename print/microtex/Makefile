PORTNAME=	microtex
DISTVERSION=	g20240805
CATEGORIES=	print devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic, cross-platform, and embeddable LaTeX rendering library
WWW=		https://github.com/NanoMichael/MicroTex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libtinyxml2.so:textproc/tinyxml2

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GNOME=	cairomm glibmm gtkmm30 pangomm
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	NanoMichael
GH_PROJECT=	MicroTeX
GH_TAGNAME=	0e3707f

PORTSCOUT=	skipv:xml-def

.include <bsd.port.mk>
