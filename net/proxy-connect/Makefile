# Created by: alfred@FreeBSD.org
# $FreeBSD$

PORTNAME=	proxy-connect
PORTVERSION=	100
CATEGORIES=	net
MASTER_SITES=	http://www.exit2shell.com/~skreuzer/distfiles/ \
				http://www.atarininja.org/distfiles/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Command to make network connections via SOCKS and HTTPS proxies

BROKEN=		unfetchable

USES=	tar:bzip2

EXENAME=	${PORTNAME}

PLIST_FILES=	sbin/${EXENAME}

do-build:
		cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${EXENAME} connect.c

do-install:
		${INSTALL_PROGRAM} \
			${WRKSRC}/${EXENAME} ${STAGEDIR}${PREFIX}/sbin/${EXENAME}

.include <bsd.port.mk>
