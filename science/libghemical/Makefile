PORTNAME=	libghemical
PORTVERSION=	3.0.0
PORTREVISION=	20
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port
WWW=		https://www.bioinformatics.org/ghemical/ghemical/index.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	obabel:science/openbabel \
		intltool-update:textproc/intltool \
		ld:devel/binutils
LIB_DEPENDS=	libblas.so:math/blas \
		libint.so:science/libint \
		libf2c.so:lang/f2c \
		liblapack.so:math/lapack \
		libmpqc.so:science/mpqc

USES=		fortran gettext gl gmake libtool localbase pathfix pkgconfig
USE_CXXSTD=	c++98
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--enable-mpqc
LDFLAGS+=	-lSCbasis -lSCcints -lSCclass -lSCcontainer -lSCdft -lSCgroup \
		-lSCintv3 -lSCisosurf -lSCkeyval -lSCmbpt -lSCmbptr12 -lSCmisc \
		-lSCmolecule -lSCoint3 -lSCoptimize -lSCoptions -lSCpsi \
		-lSCref -lSCrender -lSCscf -lSCscmat -lSCsolvent -lSCstate \
		-lSCsymmetry -lSCwfn -lgfortran -lpthread -lblas -llapack
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
