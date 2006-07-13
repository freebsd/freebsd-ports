# New ports collection makefile for: ghemical
# Date created:			May 4, 2003
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	2.01
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmpqc.a:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c \
		openbabel:${PORTSDIR}/science/openbabel
LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		ghemical:${PORTSDIR}/science/libghemical

USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libglade2 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mopac7 --enable-mpqc --enable-openbabel
PLIST_SUB=      GHEMICAL_VERSION="${PORTVERSION}"

MAKE_ENV=       PKG_CONFIG=${LOCALBASE}/pkg-config

.include <bsd.port.mk>
