PORTNAME=	belle-sip
DISTVERSION=	5.1.32
PORTREVISION=	1
CATEGORIES=	net java

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP (RFC 3261) implementation written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libbctoolbox.so:net/bctoolbox \
		libbelr.so:textproc/belr

USES=		cmake cpe tar:bz2
CPE_VENDOR=	linphone
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	6cfa9cf048905756bb9e729ccc029ad19b36ca76
USE_JAVA=	yes
JAVA_BUILD=	jre
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_TESTS=NO

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
