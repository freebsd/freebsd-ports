# Created by: sviat
# $FreeBSD$

PORTNAME=	sasp
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	LOCAL/ahze \
		http://people.freebsd.org/~ahze/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that permits to use a gateway whatever IP we have

LIB_DEPENDS=	libnet.so:net/libnet

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/sasp

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include -o sasp sasp.c \
		${LDFLAGS} -L${LOCALBASE}/lib -lpcap -lnet)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sasp ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
