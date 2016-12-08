# $FreeBSD$

PORTNAME=	opencinematools
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE
DISTVERSIONSUFFIX=	-src

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tools for creating multi-reel DCPs from MXF source material

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15 \
		libexpat.so:textproc/expat2 \
		libasdcp.so:multimedia/asdcplib

USES=		dos2unix zip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/unix

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/mkcpl bin/mkpkl bin/mkmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkcpl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkpkl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkmap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
