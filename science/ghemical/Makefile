# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	3.0.0
PORTREVISION=	17
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	release20111012 current

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computational chemistry software package

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libghemical.so:science/libghemical \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libint.so:science/libint \
		liblapack.so:math/lapack \
		liboglappth.so:science/liboglappth \
		libopenbabel.so:science/openbabel \
		libmopac7.so:biology/mopac \
		libmpqc.so:science/mpqc
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++11-lang fortran gettext gl gmake gnome pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk --enable-threads --enable-openbabel
USE_GNOME=	cairo gdkpixbuf2 gtk20 libglade2 intltool pangox-compat
USE_GL=		gl glu
USE_XORG=	x11

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-c++11-narrowing # prevent build errors: non-constant-expression cannot be narrowed from type 'double' to 'fGL' (aka 'float')

PLIST_SUB=	GHEMICAL_VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|"mozilla "|"xdg-open "|' ${WRKSRC}/src/gtk_app.cpp

.include <bsd.port.mk>
