PORTNAME=	evhz
DISTVERSION=	g20210920
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~iank/${PORTNAME}/archive/${SR_HT_COMMIT}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tool for measuring evdev event rate (mouse polling rate)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		compiler localbase

SR_HT_COMMIT=	35b7526e0655522bbdf92f6384f4e9dff74f38a0
WRKSRC=		${WRKDIR}/${PORTNAME}-${SR_HT_COMMIT}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
