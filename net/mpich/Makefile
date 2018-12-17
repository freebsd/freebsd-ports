# $FreeBSD$

PORTNAME=	mpich
PORTVERSION=	3.2.1
PORTREVISION=	3
CATEGORIES=	net parallel
MASTER_SITES=	http://www.mpich.org/static/downloads/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable implementation of MPI-1, MPI-2 and MPI-3

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libhwloc.so:devel/hwloc

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.* mpich2-[0-9]*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c11 libtool pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS FORTRAN
OPTIONS_GROUP=		PM
OPTIONS_GROUP_PM=	GFORKER HYDRA
OPTIONS_RADIO=		DEFAULTPM
OPTIONS_RADIO_DEFAULTPM=DGFORKER DHYDRA
OPTIONS_DEFAULT=	FORTRAN GFORKER HYDRA DHYDRA
OPTIONS_SUB=		yes

FORTRAN_USES=			fortran
FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_CONFIGURE_ON=		\
	MPICH_MPICC_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPICXX_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIF77_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIFORT_LDFLAGS="${MPICH_LDFLAGS}"
MPICH_LDFLAGS=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER} -B${LOCALBASE}/bin

PM_DESC=	Process managers
GFORKER_DESC=	Simple local process manager
HYDRA_DESC=	Parallel process manager
DEFAULTPM_DESC=	Default process manager
DGFORKER_DESC=	Make gforker the default process manager
DHYDRA_DESC=	Make hydra the default process manager

CONFIGURE_ARGS=	--enable-fast="" --with-hwloc-prefix=${LOCALBASE} \
		ac_cv_path_BASH_SHELL="" \
		pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		MPICHLIB_CFLAGS="${CFLAGS}" CFLAGS="" \
		MPICHLIB_CPPFLAGS="${CPPFLAGS}" CPPFLAGS="" \
		MPICHLIB_CXXFLAGS="${CXXFLAGS}" CXXFLAGS="" \
		MPICHLIB_FFLAGS="${FFLAGS}" FFLAGS="" \
		MPICHLIB_FCFLAGS="${FCFLAGS}" FCFLAGS="" \
		MPICHLIB_LDFLAGS="${LDFLAGS}" LDFLAGS="" \
		MPICHLIB_LIBS="${LIBS}" LIBS=""

.include <bsd.port.options.mk>

.for pm in ${OPTIONS_GROUP_PM}
. if ${PORT_OPTIONS:M${pm}}
.  if empty(PMLIST)
PMLIST=		${pm:tl}
.  elif ${PORT_OPTIONS:MD${pm}}
PMLIST:=	${pm:tl},${PMLIST}
.  else
PMLIST:=	${PMLIST},${pm:tl}
.  endif
. endif
.endfor

.if empty(PMLIST)
CONFIGURE_ARGS+=--without-pm
PLIST_SUB+=	EXEC="@comment " EXECGFORKER="@comment "
.else
CONFIGURE_ARGS+=--with-pm=${PMLIST}
PLIST_SUB+=	EXEC=""
.if ${PMLIST:M*,gforker*}
PLIST_SUB+=	EXECGFORKER=""
.else
PLIST_SUB+=	EXECGFORKER="@comment "
.endif
.endif

post-patch:
	@${RM} -r ${WRKSRC}/www

.include <bsd.port.mk>
