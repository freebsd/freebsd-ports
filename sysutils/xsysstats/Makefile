# $FreeBSD$

PORTNAME=	xsysstats
PORTVERSION=	1.51
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	XCONTRIB/utilities
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System information display tool

GNU_CONFIGURE=	yes
USES=		gmake xorg
USE_XORG=	x11

ALL_TARGET=	xsysstats

PLIST_FILES=	bin/xsysstats man/man1/${PORTNAME}.1.gz

pre-patch:
	${RM} ${WRKSRC}/headers.h && ${TOUCH} ${WRKSRC}/headers.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
