# $FreeBSD$

PORTNAME=	esys-particle
DISTVERSION=	2.3.5
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://launchpad.net/esys-particle/trunk/${DISTVERSION}/+download/
DISTNAME=	ESyS-Particle-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Particle-based numerical modelling software

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpi.so:net/mpich

USES=		cmake:outsource fortran
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libboost_filesystem.so

pre-build:
	@${ECHO} "static int s_bzr_revision=-1;" > ${WRKSRC}/bzrversion.h

.include <bsd.port.mk>
