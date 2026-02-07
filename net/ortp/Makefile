PORTNAME=	ortp
DISTVERSION=	5.4.72
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library
WWW=		https://gitlab.linphone.org/BC/public/ortp

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
