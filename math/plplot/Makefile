# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	5.0.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.patch1.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	F77="${FC}" FFLAGS="${FFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GDINCDIR="${LOCALBASE}/include/gd" \
		GDLIBDIR="${LOCALBASE}/lib" \
		XINCDIR="${X11BASE}/include" \
		XLIBDIR="${X11BASE}/lib" \
		PLPLOT_PREFIX="${PREFIX}/share/plplot" \
		DEMOS_DIR="${PREFIX}/share/examples/plplot" \
		INFO_DIR="${PREFIX}/info" \
		M4="${LOCALBASE}/bin/gm4"
CONFIGURE_ARGS=	--disable-tk --disable-tcl --disable-itcl --disable-python \
		--with-double
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
