# Created by: Erik B Knudsen
# $FreeBSD$

PORTNAME=	mcstas-comps
PORTVERSION=	2.1
#PORTREVISION=	beta
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/mcstas-${PORTVERSION}/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	McStas-${PORTVERSION}-UNIX-src.tar.gz
DIST_SUBDIR=	mcstas
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Component Library for McStas Monte Carlo neutron ray tracing

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/mcstas/${PORTVERSION}/bin/mcstas:${PORTSDIR}/science/mcstas

USES=		cmake gmake bison:build
# Apparently cmake does not generate an install/strip target if nothing
# is supposed to be stripped, so override the cmake-default install
# target of install/strip by resetting STRIP
STRIP=		#none
CMAKE_ARGS=	"-Denable_mcstas=1"
GNU_CONFIGURE=	yes
#USE_GMAKE= yes
#USE_BISON= yes

.include <bsd.port.pre.mk>

# this is necessary since mcxtrace and mcstas are packaged in a
# single tarball in which the kernel, component library, and tool
# tarballs reside
post-fetch:
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
	cd ${DISTDIR}/${DIST_SUBDIR};\
	${TAR} --strip-components 1 -xzf ${DISTFILES} McStas-${PORTVERSION}-UNIX-src/${DISTNAME}.tar.gz;
.endif

.include <bsd.port.post.mk>
