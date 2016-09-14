# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	uchardet
PORTVERSION=	0.0.1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	yuri@rawbw.com
COMMENT=	Universal charset detection library by Mozilla

LICENSE=	MPL

BROKEN=		Unfetchable (google code has gone away)

USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's|_SHARE|_PREFIX|' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
