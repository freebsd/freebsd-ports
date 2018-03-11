# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liboglappth
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

GNU_CONFIGURE=  yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_GL=		glu

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
