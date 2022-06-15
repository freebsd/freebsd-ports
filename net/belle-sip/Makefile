PORTNAME=	belle-sip
PORTVERSION=	5.1.32
CATEGORIES=	net java
MASTER_SITES=	https://gitlab.linphone.org/BC/public/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP (RFC 3261) implementation written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libbctoolbox.so:net/bctoolbox \
		libbelr.so:textproc/belr

USES=		cmake cpe tar:bz2
CPE_VENDOR=	linphone
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
