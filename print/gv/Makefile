# ex:ts=8
# Ports collection makefile for:  gv
# Date created:			  16 Apr 1996
# Whom:				  tg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gv
PORTVERSION=	3.6.9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A PostScript and PDF previewer

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	xpm ice sm xext xmu x11
USE_GHOSTSCRIPT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="-liconv"
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/X11 \
			--enable-setenv-code \
			--enable-SIGCHLD-fallback

MAN1=		gv.1 gv-update-userconfig.1
INFO=		gv
PLIST_FILES=	bin/gv \
		bin/gv-update-userconfig \
		${DATADIR_REL}/gv_class.ad \
		${DATADIR_REL}/gv_copyright.dat \
		${DATADIR_REL}/gv_spartan.dat \
		${DATADIR_REL}/gv_system.ad \
		${DATADIR_REL}/gv_user.ad \
		${DATADIR_REL}/gv_user_res.dat \
		${DATADIR_REL}/gv_widgetless.dat \
		lib/X11/app-defaults/GV
PLIST_DIRS=	${DATADIR_REL}

.include <bsd.port.mk>
