# $FreeBSD$

PORTNAME=	OpenCorsairLink
DISTVERSION=	g20191001
CATEGORIES=	sysutils

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Support for CorsairLink Devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	audiohacked
GH_TAGNAME=	4234f4f

PLIST_FILES=	bin/${PORTNAME}

LDFLAGS+=	-lm

MAKE_ENV=	GIT_VERSION=${GH_TAGNAME}

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.elf ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
