PORTNAME=	tcptraceroute
PORTVERSION=	1.5beta7
DISTVERSIONPREFIX=	tcptraceroute-
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute implementation using TCP packets
WWW=		https://github.com/mct/tcptraceroute

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnet.so:net/libnet

USES=		gmake localbase

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

GH_ACCOUNT=	mct
USE_GITHUB=	yes

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
