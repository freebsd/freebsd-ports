# Created by: Warren Toomey <wkt@cs.adfa.edu.au>

PORTNAME=	pktsuckers
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	ftp://minnie.tuhs.org/pub/NetSecurity/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Log contents of unwanted UDP packets and TCP connections

DEPRECATED=	Abandonware, last release from somewhere around 1999
EXPIRATION_DATE=2022-03-31

PLIST_FILES=	libexec/tcpsuck libexec/udpsuck

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/tcpsuck.c ${WRKSRC}/udpsuck.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpsuck ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/udpsuck ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
