# Created by: Erik B Knudsen
# $FreeBSD$

PORTNAME=	Mcstas-Tools
PORTVERSION=	2.2a
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/mcstas-${PORTVERSION}/unix/McStas-${PORTVERSION}-UNIX-src/
PKGNAMEPREFIX=	p5-
DISTNAME=	mcstas-tools-perl-${PORTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Perl based tools for the McStas neutron ray tracing package

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Tk>0:x11-toolkits/p5-Tk \
		p5-PGPLOT>=2.21:graphics/p5-PGPLOT	\
		PDL>0:math/PDL \
		${LOCALBASE}/bin/mcstas:science/mcstas

USES=		cmake gmake perl5
CMAKE_ARGS=	-Denable_mcstas=1
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-install
SUB_LIST=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
