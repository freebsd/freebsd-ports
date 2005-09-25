# ex:ts=8
# New ports collection makefile for:   gerris
# Date created:                        Sun Sep 18 12:36:38 CEST 2005
# Whom:                                Oliver Dunkl <odunkl@gmx.net>
#
# $FreeBSD$
#

PORTNAME=		gerris
PORTVERSION=		0.6.0
CATEGORIES=		science math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gfs

PATCH_SITES=		${MASTER_SITE_SOURCEFORGE}gfs/ \
			http://members.aon.at/odunkl/downloads/patches/
PATCHFILES=		gerris-0.6-patch-1.gz \
			gerris-0.6-patch-2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		odunkl@gmx.net
COMMENT=		A scientific CFD simulator

LIB_DEPENDS=		gts.3:${PORTSDIR}/graphics/gts

.if !defined(WITHOUT_DX)
BUILD_DEPENDS+=		dx:${PORTSDIR}/graphics/opendx
RUN_DEPENDS+=		dx:${PORTSDIR}/graphics/opendx
.else
CONFIGURE_ARGS+=	--disable-dx
.endif

USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes
USE_GNOME=		pkgconfig
USE_GETOPT_LONG=	yes
USE_REINPLACE=		yes

MPIDIR=			${LOCALBASE}/mpich

.include <bsd.port.pre.mk>

# TODO: add support for MPI
#.if exists(${MPIDIR}/bin/mpiCC)
#WITH_MPI=	yes
#.endif
#.if defined(WITH_MPI)
#PKGNAMESUFFIX+=		-mpich
#BUILD_DEPENDS+=		${MPIDIR}/bin/mpiCC:${PORTSDIR}/net/mpich
#CONFIGURE_ARGS+=	--with-mpicc=${MPIDIR}/bin/mpiCC
#MAKE_ARGS=         	LIBTOOL="${LIBTOOL} --tag=CC"
#.else
CONFIGURE_ARGS+=	--disable-mpi
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'	\
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
