PORTNAME=	chawan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~bptato/chawan/archive/
DISTNAME=	${DISTVERSIONFULL}

MAINTAINER=	hoanga@gmail.com
COMMENT=	Chawan is a text-mode web browser and pager
WWW=		https://chawan.net

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

BUILD_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libbrotlicommon.so:archivers/brotli \
		libssh2.so:security/libssh2

USES=		gmake libtool pkgconfig ssl

MAKE_ENV+=	PATH=${LOCALBASE}/nim/bin:${PATH}

WRKSRC=		${WRKDIR}/chawan-${DISTVERSIONFULL}

.include <bsd.port.mk>
