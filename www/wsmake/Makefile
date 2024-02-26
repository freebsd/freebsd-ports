PORTNAME=	wsmake
PORTVERSION=	0.7.901
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for production and maintenance of web sites
WWW=		https://sourceforge.net/projects/wsmake/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-gwsmake=no --enable-iswmake=no

INFO=		wsmake iwsmake gwsmake

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
