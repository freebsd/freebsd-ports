# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	tcptraceroute
PORTVERSION=	1.5beta7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute implementation using TCP packets

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnet.so:net/libnet

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:^[0-9]

GNU_CONFIGURE=	yes
USES=		gmake localbase

PORTDOCS=	*

GH_ACCOUNT=	mct
USE_GITHUB=	yes

.include <bsd.port.mk>
