PORTNAME=	belle-sip
DISTVERSION=	5.4.24
CATEGORIES=	net java

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP (RFC 3261) implementation written in C
WWW=		https://www.linphone.org/technical-corner/belle-sip.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit \
		${LOCALBASE}/lib/libbelr.a:textproc/belr
LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c

USES=		cmake cpe java:build tar:bz2
CPE_VENDOR=	linphone
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_TUPLE=	https://gitlab.linphone.org/BC/public:external:cpp-httplib:a2ed0d11c134b6c23da275103b5183b423cea8a8:httplib/tester/cpp-httplib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STRICT=NO \
		-DENABLE_TESTS=NO \
		-DENABLE_UNIT_TESTS=NO

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
