# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	3.0.0
PORTREVISION=	10
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	obabel:science/openbabel \
		intltool-update:textproc/intltool \
		ld:devel/binutils
LIB_DEPENDS=	libmpqc.so:science/mpqc \
		libf2c.so:lang/f2c

USES=		fortran gettext gmake pathfix pkgconfig libtool
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--enable-mpqc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lSCbasis -lSCcints -lSCclass \
		-lSCcontainer -lSCdft -lSCgroup -lSCintv3 -lSCisosurf \
		-lSCkeyval -lSCmbpt -lSCmbptr12 -lSCmisc -lSCmolecule \
		-lSCoint3 -lSCoptimize -lSCoptions -lSCpsi -lSCref \
		-lSCrender -lSCscf -lSCscmat -lSCsolvent -lSCstate \
		-lSCsymmetry -lSCwfn \
		-lgfortran -lpthread -lblas -llapack
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
