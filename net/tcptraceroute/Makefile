# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	tcptraceroute
PORTVERSION=	1.5beta7
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute implementation using TCP packets

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		gmake

PORTDOCS=	*

GH_ACCOUNT=	mct
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
USE_GITHUB=	yes

.include <bsd.port.mk>
