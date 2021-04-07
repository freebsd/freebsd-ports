PORTNAME=	belr
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.linphone.org/releases/sources/belr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language recognition library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO
WRKSRC= 	${WRKDIR}/${DISTNAME}-0

.include <bsd.port.mk>
