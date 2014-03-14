# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current
		
MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	obabel:${PORTSDIR}/science/openbabel \
		intltool-update:${PORTSDIR}/textproc/intltool \
		ld:${PORTSDIR}/devel/binutils
LIB_DEPENDS+=	mpqc:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c

USES=		fortran gettext gmake pathfix pkgconfig
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

CONFIGURE_ARGS+=	--enable-mpqc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

NO_STAGE=	yes
.include <bsd.port.mk>
