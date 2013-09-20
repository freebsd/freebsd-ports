# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liboglappth
PORTVERSION=	1.0.0
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current
	
MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

GNU_CONFIGURE=  yes

USE_GL=		glut
USES=	pathfix

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.mk>
