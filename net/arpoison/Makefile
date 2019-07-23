# $FreeBSD$

PORTNAME=	arpoison
DISTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://www.arpoison.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	UNIX arp cache update utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USES=		gmake

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
