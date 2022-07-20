PORTNAME=	grepip
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://komquats.com/distfiles/ \
		LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Print lines with IP addresses matching a pattern in CIDR format

LIB_DEPENDS=	libpcre.so:devel/pcre

PLIST_FILES=	bin/grepip
PORTDOCS=	README.txt
USES=		localbase

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -c patricia.c; \
	${CC} ${CFLAGS} -o grepip grepip.c patricia.o ${LIBS} -lpcre

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grepip ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
