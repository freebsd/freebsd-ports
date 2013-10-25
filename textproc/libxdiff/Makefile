# Created by: ijliao
# $FreeBSD$

PORTNAME=	libxdiff
PORTVERSION=	0.23
CATEGORIES=	textproc
MASTER_SITES=	http://www.xmailserver.org/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Create file differences/patches to both binary and text files

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

LIBFILES=	libxdiff.a libxdiff.la libxdiff.so libxdiff.so.0

do-install:
	${INSTALL_DATA} ${WRKSRC}/xdiff/xdiff.h ${STAGEDIR}${PREFIX}/include
.for libs in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/xdiff/.libs/${libs} ${STAGEDIR}${PREFIX}/lib/
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xdiff.3 ${STAGEDIR}${MAN1PREFIX}/man/man3

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxdiff.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxdiff.so.0

.include <bsd.port.mk>
