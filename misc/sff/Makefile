PORTNAME=	sff
DISTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	https://codeberg.org/sylphenix/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	sylphenix@outlook.com
COMMENT=	Simple and fast terminal file manager
WWW=		https://codeberg.org/sylphenix/sff

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
USE_CSTD=	c11

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
