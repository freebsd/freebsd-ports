# Created by: joseph@randomnetworks.com
# $FreeBSD$

PORTNAME=	sendip
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.earth.li/projectpurple/files/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	SendIP is a commandline tool to allow sending arbitrary IP packets

USES=		gmake perl5
USE_LDCONFIG=	yes

MAN1=		sendip.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not compile on FreeBSD 9.X
.endif

.include <bsd.port.post.mk>
