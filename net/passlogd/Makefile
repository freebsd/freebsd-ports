# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	passlogd
PORTVERSION=	0.1f
CATEGORIES=	net
MASTER_SITES=	http://www.morphine.com/void/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Intercept and dump syslog remote log packets

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

PLIST_FILES=	sbin/passlogd

post-patch:
	${REINPLACE_CMD} -e "s|.(CXX)|${CC} ${CFLAGS}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/passlogd ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
