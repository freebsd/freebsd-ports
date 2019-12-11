# $FreeBSD$

PORTNAME=	esys-particle
DISTVERSION=	2.3.5
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/
DISTNAME=	ESyS-Particle-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Particle-based numerical modelling software

LICENSE=	APACHE20

BROKEN_FreeBSD_13=	The upstream doesn't answer bug reports: https://bugs.launchpad.net/esys-particle/+bug/1808617

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpi.so:net/mpich

USES=		cmake fortran
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libboost_filesystem.so

pre-build:
	@${ECHO} "static int s_bzr_revision=-1;" > ${WRKSRC}/bzrversion.h

.include <bsd.port.mk>
