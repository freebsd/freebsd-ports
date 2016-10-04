# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	uchardet
PORTVERSION=	0.0.1
CATEGORIES=	textproc
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/${PORTNAME}/

MAINTAINER=	yuri@rawbw.com
COMMENT=	Universal charset detection library by Mozilla

LICENSE=	MPL

USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's|_SHARE|_PREFIX|' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
