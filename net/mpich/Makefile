# $FreeBSD$

PORTNAME=	mpich
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.mpich.org/static/downloads/${DISTVERSION}/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Portable implementation of MPI-1, MPI-2 and MPI-3

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libhwloc.so:${PORTSDIR}/devel/hwloc

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.* mpich2-[0-9]*
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS FORTRAN
OPTIONS_GROUP=		PM
OPTIONS_GROUP_PM=	GFORKER HYDRA
OPTIONS_RADIO=		DEFAULTPM
OPTIONS_RADIO_DEFAULTPM=DGFORKER DHYDRA
OPTIONS_DEFAULT=	FORTRAN HYDRA DHYDRA
OPTIONS_SUB=		yes

FORTRAN_CONFIGURE_ENABLE=	f77 fc
FORTRAN_USES=			fortran

GFORKER_DESC=	Simple local process manager
HYDRA_DESC=	Parallel process manager
DGFORKER_DESC=	Make gforker the default process manager
DHYDRA_DESC=	Make hydra the default process manager

CONFIGURE_ARGS=	--with-hwloc-prefix=${LOCALBASE} ac_cv_path_BASH_SHELL=""

.include <bsd.port.options.mk>

.for pm in ${OPTIONS_GROUP_PM}
. if ${PORT_OPTIONS:M${pm}}
.  if empty(PMLIST)
PMLIST=		${pm:L}
.  elif ${PORT_OPTIONS:MD${pm}}
PMLIST:=	${pm:L},${PMLIST}
.  else
PMLIST:=	${PMLIST},${pm:L}
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
	@${REINPLACE_CMD} \
		-e '/pkgconfigdir=/s,=.*,=$$prefix/libdata/pkgconfig,' \
		${WRKSRC}/configure ${WRKSRC}/src/openpa/configure

.include <bsd.port.mk>
