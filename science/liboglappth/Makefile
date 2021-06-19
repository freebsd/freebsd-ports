# Created by: Nakata Maho <maho@FreeBSD.org>

PORTNAME=	liboglappth
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://bioinformatics.org/ghemical/download/release20111012/	\
		http://bioinformatics.org/ghemical/download/current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

GNU_CONFIGURE=  yes
INSTALL_TARGET=	install-strip
USES=		gl libtool pathfix
USE_GL=		glu

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
