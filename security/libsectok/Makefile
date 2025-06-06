PORTNAME=	libsectok
DISTVERSION=	20030619
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO 7816 Smartcard API Library
WWW=		http://www.citi.umich.edu/projects/smartcard/sectok.html

LICENSE=	LicenseRef-UMich
LICENSE_NAME=	University of Michigan License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=		Last upstream release in 2003 and no longer maintained
EXPIRATION_DATE=	2025-06-30

USE_LDCONFIG=	yes

LDFLAGS+= -Wl,-soname=${PORTNAME}.so.3

PLIST_FILES=	include/sectok.h lib/libsectok.a lib/libsectok.so \
		lib/libsectok.so.3 share/man/man3/sectok.3.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^VERSION/s|3.1|3| ; \
		 s|^CFLAGS=|CFLAGS+=| ; \
		 s|-g |$${CPPFLAGS} | ; \
		 s|^LDFLAGS=|LDFLAGS+=| ; \
		 s|-x .* -shared|-shared| ; \
		 s|^CC=|CC?=| ; \
		 /^LD/s|ld|$$(CC)| ; \
		 s|-fpic|-fPIC|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} sectok.h \
		${STAGEDIR}${PREFIX}/include)
	(cd ${WRKSRC} && ${INSTALL_DATA} libsectok.a \
		${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC} && ${INSTALL_LIB} libsectok.so.3 \
		${STAGEDIR}${PREFIX}/lib)
	${LN} -s libsectok.so.3 ${STAGEDIR}${PREFIX}/lib/libsectok.so
	(cd ${WRKSRC} && ${INSTALL_MAN} sectok.3 \
		${STAGEDIR}${PREFIX}/share/man/man3)

.include <bsd.port.mk>
