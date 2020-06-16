# $FreeBSD$

PORTNAME=	mpsolve
DISTVERSION=	3.2.1
CATEGORIES=	math
MASTER_SITES=	https://numpi.dm.unipi.it/_media/software/mpsolve/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiprecision rootfinder for complex roots of univariate polynomials

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libtcmalloc_minimal.so:devel/google-perftools

USES=		autoreconf compiler:c++11-lang gettext-runtime gmake gnome \
		libtool localbase pkgconfig shared-mime-info tar:bz2
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_DESC=		Graphical UI to solve polynomial equations visually
GUI_CONFIGURE_OFF=	--disable-ui
GUI_USES=		bison desktop-file-utils qt:5
GUI_USE=		QT=core,gui,widgets,buildtools_build

.include <bsd.port.mk>
