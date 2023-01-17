PORTNAME=	libzen
DISTVERSION=	0.4.40
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/source/${PORTNAME}/${DISTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ZenLib used by MediaInfo and its library
WWW=		https://mediaarea.net/en/MediaInfo

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/../../License.txt

USES=		cmake compiler:c++11-lang dos2unix pathfix pkgconfig tar:bz2
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.c *.cmake.in *.cpp *.h *.pc.in *.txt
DOS2UNIX_WRKSRC=	${WRKDIR}

WRKSRC=		${WRKDIR}/ZenLib/Project/CMake

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '/^Libs_Static/d' ${PATCH_WRKSRC}/libzen.pc.in

.include <bsd.port.mk>
