# $FreeBSD$

PORTNAME=	wxmacmolplt
DISTVERSIONPREFIX=	v
DISTVERSION=	7.7-43
DISTVERSIONSUFFIX=	-g9a46f7a
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface principally for the GAMESS program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gl gmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brettbode
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
USE_WX=		3.1
USE_GL=		gl glew glu

.include <bsd.port.mk>
