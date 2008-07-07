# New ports collection makefile for: ghemical
# Date created:			May 4, 2003
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	2.10
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c \
		openbabel:${PORTSDIR}/science/openbabel
LIB_DEPENDS=	mpqc:${PORTSDIR}/science/mpqc \
		glut:${PORTSDIR}/graphics/libglut \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		ghemical:${PORTSDIR}/science/libghemical \
		mopac7:${PORTSDIR}/biology/mopac

USE_FORTRAN=	yes
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libglade2 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mopac7 --enable-gamess --enable-mpqc --enable-openbabel
PLIST_SUB=      GHEMICAL_VERSION="${PORTVERSION}"

MAKE_ENV=       PKG_CONFIG=${LOCALBASE}/pkg-config

.include <bsd.port.mk>
