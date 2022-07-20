PORTNAME=	rtfreader
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.fiction.net/blong/programs/
DISTNAME=	ms-rtf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable application/ms-rtf parser

ALL_TARGET=	rtfreader
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/rtfreader

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtfreader ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
