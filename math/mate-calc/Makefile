PORTNAME=	mate-calc
PORTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE calculator tool based on the old calctool for OpenWindows
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

GLIB_SCHEMAS=	org.mate.calc.gschema.xml

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
