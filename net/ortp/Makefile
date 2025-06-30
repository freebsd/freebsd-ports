PORTNAME=	ortp
DISTVERSION=	5.4.24
CATEGORIES=	net

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library
WWW=		https://www.linphone.org/technical-corner/ortp.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit

USES=		cmake compiler:c11 ssl
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_DOC=NO -DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

LDFLAGS+=	-lpthread

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
