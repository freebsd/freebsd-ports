PORTNAME=	belle-sip
DISTVERSION=	5.4.28
CATEGORIES=	net java

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP (RFC 3261) implementation written in C
WWW=		https://www.linphone.org/technical-corner/belle-sip.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libbctoolbox.so:net/bctoolbox \
		libbcunit.so:devel/bcunit \
		libbelr.so:textproc/belr

USES=		cmake cpe java:build tar:bz2
CPE_VENDOR=	linphone
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STRICT=NO \
		-DENABLE_TESTS=NO
CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		ENABLE_UNIT_TESTS

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
