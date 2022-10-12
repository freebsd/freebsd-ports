PORTNAME=	evhz
DISTVERSION=	g20210920
DISTVERSIONSUFFIX=	-0-g35b7526
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~iank/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tool for measuring evdev event rate (mouse polling rate)
WWW=		https://git.sr.ht/~iank/evhz

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		localbase
PLIST_FILES=	bin/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
