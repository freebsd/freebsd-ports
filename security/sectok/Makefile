# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sectok
PORTVERSION=	20030825
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO 7816 Smartcard Utility

LIB_DEPENDS=	libsectok.so:security/libsectok

USE_OPENSSL=	yes
USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} \
		-e '/^INCLUDES=/s|$$| ${CPPFLAGS}|' \
		-e '/^LIBS=/s|=|=${LDFLAGS} |' \
		-e '/^LIBS=/s|$$| ${LIBS}|' \
		${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
