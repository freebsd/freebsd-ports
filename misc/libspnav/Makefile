PORTNAME=	libspnav
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-7
DISTVERSIONSUFFIX=	-g907c96b
CATEGORIES=	misc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for communicating with spacenavd or 3dxsrv
WWW=		https://spacenav.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake xorg
USE_XORG=	x11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	FreeSpacenav

GNU_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libspnav.so.0.3

.include <bsd.port.mk>
