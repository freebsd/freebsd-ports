# ex:ts=8
# Ports collection makefile for:  gv
# Date created:			  16 Apr 1996
# Whom:				  tg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gv
PORTVERSION=	3.6.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	conrads@cox.net
COMMENT=	A PostScript and PDF previewer

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	xpm ice sm xext xmu x11
USE_GHOSTSCRIPT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/X11 \
			--enable-setenv-code

MAN1=		gv.1
INFO=		gv
PLIST_FILES=	bin/gv \
		lib/X11/gv/gv_class.ad \
		lib/X11/gv/gv_copyright.dat \
		lib/X11/gv/gv_spartan.dat \
		lib/X11/gv/gv_system.ad \
		lib/X11/gv/gv_user.ad \
		lib/X11/gv/gv_user_res.dat \
		lib/X11/gv/gv_widgetless.dat \
		lib/X11/app-defaults/GV
PLIST_DIRS=	lib/X11/gv

post-install:
		@${ECHO_MSG} ""
		@${ECHO_MSG} " Don't forget to remove ${HOME}/.gv if it was created "
		@${ECHO_MSG} " when a different version of gv was installed: otherwise "
		@${ECHO_MSG} " gv may fail to run. "
		@${ECHO_MSG} ""

.include <bsd.port.mk>
