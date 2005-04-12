# ex:ts=8
# Ports collection makefile for:  gv
# Date created:			  16 Apr 1996
# Whom:				  tg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gv
PORTVERSION=	3.6.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PostScript and PDF previewer

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GHOSTSCRIPT=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/X11

CPPFLAGS=	-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib

MAN1=		gv.1
INFO=		gv
PLIST_FILES=	bin/gv \
		lib/X11/app-defaults/GV \
		lib/X11/gv/gv_class.ad \
		lib/X11/gv/gv_copyright.dat \
		lib/X11/gv/gv_spartan.dat \
		lib/X11/gv/gv_system.ad \
		lib/X11/gv/gv_user.ad \
		lib/X11/gv/gv_user_res.dat

PLIST_DIRS=	lib/X11/gv

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
