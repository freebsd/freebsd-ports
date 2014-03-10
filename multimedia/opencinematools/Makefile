# $FreeBSD$

PORTNAME=	opencinematools
PORTVERSION=	1.1.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tools for creating multi-reel DCPs from MXF source material

LIB_DEPENDS=	openjpeg.2:${PORTSDIR}/graphics/openjpeg \
		expat.6:${PORTSDIR}/textproc/expat2 \
		asdcp.0:${PORTSDIR}/multimedia/asdcplib

USES=		dos2unix zip

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/mkcpl bin/mkpkl bin/mkmap

do-build:
	@cd ${WRKSRC}/build/unix && ${MAKE} ${MAKE_ENV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkcpl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkpkl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mkmap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
