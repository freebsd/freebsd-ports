# New ports collection makefile for:   gtk--
# Version required:    0.9.14
# Date created:        11 May 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.5 1998/10/20 07:35:11 asami Exp $
#

DISTNAME=	Gtk---0.9.14
PKGNAME=	gtk---0.9.14
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/gtk--/

MAINTAINER=	nacai@iname.com

BROKEN=		build

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

# Why gtk11 port renames gtk-config to gtk11-config? (patch-ae)
#GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
# for the future GNOME support
#CONFIGURE_ARGS=	--with-gnome=${X11BASE}
USE_GMAKE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
