PORTNAME=	tomsfastmath
PORTVERSION=	0.13.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	tfm-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable fixed precision math library for fast exponentiations
WWW=		https://libtom.net/

LICENSE=	PD WTFPL
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:xz

MAKEFILE=	makefile
ALL_TARGET=	default
CFLAGS+=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	include/tfm.h \
		lib/libtfm.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/headers/tfm.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtfm.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
