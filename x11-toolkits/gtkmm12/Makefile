# New ports collection makefile for:   gtk--
# Date created:        11 May 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtkmm12/Makefile,v 1.2 2006/09/10 00:51:17 mezz Exp $

PORTNAME=	gtkmm
PORTVERSION=	1.2.8
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
#DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for gtk, a x11 graphics library

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static=yes \
		--without-gnome \
		--with-sigc-prefix=${LOCALBASE}

post-install:
.for lib in gdkmm gtkmm
	@${RM} ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/lib${lib}.la
	@${MV} ${PREFIX}/lib/lib${lib}.a ${PREFIX}/lib/lib${lib}-1.2.a
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
