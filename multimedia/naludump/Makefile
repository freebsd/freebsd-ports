PORTNAME=	naludump
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.udo-richter.de/vdr/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Delete NALU fill data from h.264 TS files
WWW=		https://www.udo-richter.de/vdr/naludump.en.html

LICENSE=	GPLv2

USES=		gmake iconv:wchar_t localbase tar:tgz
USE_CXXSTD=	c++14

MAKE_ARGS+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

CFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PATCH_STRIP=	-p1

PLIST_FILES+=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
