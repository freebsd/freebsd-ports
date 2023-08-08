PORTNAME=	xporthdmv
PORTVERSION=	1.01
CATEGORIES=	multimedia
MASTER_SITES=	http://www.w6rz.net/
DISTNAME=	xport

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	The xport Transport Stream Demuxer
WWW=		https://www.w6rz.net/

USES=		zip
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/xporthdmv

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/xport.c -o ${WRKSRC}/xporthdmv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xporthdmv ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
