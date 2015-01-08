# Created by: Erik B Knudsen <erkn@fysik.dtu.dk>
# $FreeBSD$

PORTNAME=	mcstas
PORTVERSION=	2.1
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/${PORTNAME}-${PORTVERSION}/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	McStas-${PORTVERSION}-UNIX-src.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Monte Carlo neutron ray tracing package

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

USES=		cmake gmake bison:build
#should perhaps use the toolchain file - but remember the arch
CMAKE_ARGS=	"-Denable_mcstas=1"
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# this is necessary since mcxtrace and mcstas are packaged in a
# single tarball in which the kernel, component library, manual,
# and tool tarballs reside
post-fetch:
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
	cd ${DISTDIR}/${DIST_SUBDIR};\
	${TAR} --strip-components 1 -xzf ${DISTFILES} McStas-2.1-UNIX-src/${DISTNAME}.tar.gz;
.endif

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/mcstas/2.1/bin/mcstas
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/mcstas/2.1/bin/mcformat

.include <bsd.port.post.mk>
