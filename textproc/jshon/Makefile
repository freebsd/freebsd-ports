# $FreeBSD$

PORTNAME=	jshon
PORTVERSION=	20131105
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JSON parser for the shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	keenerd

USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/jshon man/man1/jshon.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
