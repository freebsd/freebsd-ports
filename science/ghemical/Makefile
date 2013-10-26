# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c \
		obabel:${PORTSDIR}/science/openbabel \
		ld:${PORTSDIR}/devel/binutils
RUN_DEPENDS=	f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	mpqc:${PORTSDIR}/science/mpqc \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		ghemical:${PORTSDIR}/science/libghemical \
		oglappth:${PORTSDIR}/science/liboglappth \
		mopac7:${PORTSDIR}/biology/mopac

USES=		pkgconfig gettext
USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libglade2
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gamess --enable-mpqc --enable-openbabel --enable-gtk --enable-threads --enable-mopac7
PLIST_SUB=	GHEMICAL_VERSION="${PORTVERSION}"

MAKE_ENV=	PKG_CONFIG=${LOCALBASE}/pkg-config

NO_STAGE=	yes
.include <bsd.port.mk>
