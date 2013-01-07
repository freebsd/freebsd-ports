# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.99.1
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/release20090911/ \
		http://bioinformatics.org/ghemical/download/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	obabel:${PORTSDIR}/science/openbabel \
		mopac7:${PORTSDIR}/biology/mopac \
		intltool-update:${PORTSDIR}/textproc/intltool \
		ld:${PORTSDIR}/devel/binutils
LIB_DEPENDS+=	mpqc:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c

USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes
USE_GETTEXT=	yes
USE_PKGCONFIG=	build

USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--enable-mpqc
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
