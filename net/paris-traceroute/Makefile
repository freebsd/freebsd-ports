# Created by: dikshie@sfc.wide.ad.jp
# $FreeBSD$

PORTNAME=	paris-traceroute
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://paris-traceroute.net/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Paris traceroute is network diagnosis and measurement tools

DEPRECATED=	Legacy paris-traceroute is not supported anymore. Use net/scamper instead
EXPIRATION_DATE=2018-03-31

GNU_CONFIGURE=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-current

PLIST_FILES=	bin/paris-traceroute

.include <bsd.port.mk>
