# $FreeBSD$

PORTNAME=	lrslib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	062
DISTVERSIONSUFFIX=	+autotools-2017-03-03
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse search algorithm for vertex enumeration/convex hull problems

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpi.so:net/mpich

USES=		autoreconf fortran gmake libtool localbase:ldflags # fortran because it's built with mpic++
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	mkoeppe
USE_LDCONFIG=	yes

LDFLAGS+=	-lthr

post-stage:
	@${RM} -r ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
