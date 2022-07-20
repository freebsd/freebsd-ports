PORTNAME=	ortp
PORTVERSION=	5.1.32
CATEGORIES=	net

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c11
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	23439fba3b800c2fdb105af748ca018f51146d57
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_DOC=NO -DENABLE_STATIC=NO -DENABLE_STRICT=NO \
			-DCMAKE_PREFIX_PATH=${LOCALBASE}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
