# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sectok
PORTVERSION=	20030825
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO 7816 Smartcard Utility

LIB_DEPENDS=	libsectok.so:${PORTSDIR}/security/libsectok

USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INCLUDES=/s|$$| $${CPPFLAGS}| ; \
		 /^LIBS=/s|$$| $${LDFLAGS}| ; \
		 s|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS?=|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
