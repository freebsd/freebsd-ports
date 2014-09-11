# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	3.0.0
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c \
		obabel:${PORTSDIR}/science/openbabel \
		ld:${PORTSDIR}/devel/binutils
RUN_DEPENDS=	f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	libmpqc.so:${PORTSDIR}/science/mpqc \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libghemical.so:${PORTSDIR}/science/libghemical \
		liboglappth.so:${PORTSDIR}/science/liboglappth \
		libmopac7.so:${PORTSDIR}/biology/mopac

USES=		fortran gettext gmake pkgconfig
USE_GNOME=	glib20 gtk20 libglade2
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gamess --enable-mpqc --enable-openbabel --enable-gtk --enable-threads --enable-mopac7
PLIST_SUB=	GHEMICAL_VERSION="${PORTVERSION}"

CPPFLAGS=	-I${LOCALBASE}/include

MAKE_ENV=	PKG_CONFIG=${LOCALBASE}/pkg-config

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
