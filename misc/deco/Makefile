PORTNAME=	deco
PORTVERSION=	3.9
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/Deco%20Sources/${PORTVERSION}
PKGNAMESUFFIX=	-misc
DISTNAME=	deco39

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demos Commander, a free Norton Commander clone
WWW=		https://deco.sourceforge.net/

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

.include <bsd.port.mk>
