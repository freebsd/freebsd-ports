# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	choparp
PORTVERSION=	20150613
DISTVERSIONPREFIX=	release/
CATEGORIES=	net-mgmt

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple proxy arp daemon

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	quinot
USE_RC_SUBR=	choparp
LDFLAGS+=	-lpcap

PLIST_FILES=	sbin/choparp man/man8/choparp.8.gz

do-build:
	( cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
