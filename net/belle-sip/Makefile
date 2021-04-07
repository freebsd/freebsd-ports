PORTNAME=	belle-sip
PORTVERSION=	1.6.3
CATEGORIES=	net java
MASTER_SITES=	https://www.linphone.org/releases/sources/belle-sip/ \
		http://www.antlr3.org/download/:source2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		antlr-3.4-complete.jar:source2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP (RFC 3261) implementation written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libbctoolbox.so:net/bctoolbox

USES=		cmake
USE_JAVA=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO -DENABLE_TESTS=NO \
		-DANTLR3_JAR_PATH:FILEPATH=${WRKDIR}/antlr3.jar
JAVA_BUILD=	jre
WRKSRC=		${WRKDIR}/${DISTNAME}-0

post-extract:
	@${CP} ${DISTDIR}/antlr-3.4-complete.jar ${WRKDIR}/antlr3.jar

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
