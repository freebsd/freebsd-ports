# $FreeBSD$

PORTNAME=	dsvpn
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	security net net-vpn

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Dead Simple VPN

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1

USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/${PORTNAME}
SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} 's/^CFLAGS.*/CFLAGS\?\=${CFLAGS} ${OPTFLAGS}/g' \
	  ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
