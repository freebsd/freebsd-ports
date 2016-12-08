# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	naludump
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.udo-richter.de/vdr/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Delete NALU fill data from h.264 TS files

LICENSE=	GPLv2

USES=		alias gmake iconv:wchar_t tar:tgz
PATCH_STRIP=	-p1
CFLAGS+=	"-I${LOCALBASE}/include"
CFLAGS+=	"-L${LOCALBASE}/lib"
CFLAGS+=	${ICONV_LIB}
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"
MAKE_ARGS+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
PLIST_FILES+=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
