PORTNAME=	ortp
DISTVERSION=	5.4.28
CATEGORIES=	net

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library
WWW=		https://www.linphone.org/technical-corner/ortp.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c11 ssl
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_DOC ENABLE_UNIT_TESTS

LDFLAGS+=	-lpthread

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
