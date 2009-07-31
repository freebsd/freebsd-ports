# New ports collection makefile for: ghemical
# Date created:			May 4, 2003
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	2.98
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/release20080731/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c \
		openbabel:${PORTSDIR}/science/openbabel
RUN_DEPENDS=	f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	mpqc:${PORTSDIR}/science/mpqc \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		ghemical:${PORTSDIR}/science/libghemical \
		oglappth:${PORTSDIR}/science/liboglappth \
		mopac7:${PORTSDIR}/biology/mopac

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libglade2 pkgconfig
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gamess --enable-mpqc --enable-openbabel --enable-gtk --enable-threads --enable-mopac7 
PLIST_SUB=      GHEMICAL_VERSION="${PORTVERSION}"

MAKE_ENV=       PKG_CONFIG=${LOCALBASE}/pkg-config

.include <bsd.port.mk>
