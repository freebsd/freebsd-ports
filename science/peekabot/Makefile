# Created by: chris@officialunix.com
# $FreeBSD$

PORTNAME=	peekabot
PORTVERSION=	0.8.6
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}.x

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Distributed real-time 3D visualization tool for robotics researchers

LICENSE=	BSL GPLv3
LICENSE_COMB=	multi

BROKEN=		Does not build

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		gtkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm

USE_BZIP2=	yes
USES=	pathfix gmake
USE_GCC=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile with boost on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"/names_next_round/s|'xerces-c'|'xerces-c-3.1'|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		"/^AM_/s|-O2||" ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
