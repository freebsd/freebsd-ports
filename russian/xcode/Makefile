PORTNAME=	xcode
PORTVERSION=	4.1
CATEGORIES=	russian converters
MASTER_SITES=	http://www.rusf.ru/books/yo/src/ \
		http://pankovpv.sovietservers.com/stuff/freebsd-distfiles/
DISTNAME=	xcodesrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for converting Russian encodings with care to letter YO
WWW=		https://www.rusf.ru/books/yo/xcode.html

USES=		zip
PLIST_FILES=	bin/xcode
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	xcode

post-patch:
	${REINPLACE_CMD} -e 's,gcc -g,${CC} ${CFLAGS},' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcode ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
