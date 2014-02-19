# $FreeBSD$

PORTNAME=	mpich
DISTVERSION=	3.1rc3
CATEGORIES=	net java parallel
MASTER_SITES=	http://www.mpich.org/static/downloads/${DISTVERSION}/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Portable implementation of MPI-1, MPI-2 and MPI-3

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libhwloc.so:${PORTSDIR}/devel/hwloc
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.*
GNU_CONFIGURE=	yes
USES=		fortran libtool perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--with-hwloc-prefix=${LOCALBASE}
CONFIGURE_ENV=	FCFLAGS="${FFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} \
		-e '/pkgconfigdir=/s,=.*,=$$prefix/libdata/pkgconfig,' \
		${WRKSRC}/configure ${WRKSRC}/src/openpa/configure

.include <bsd.port.mk>
