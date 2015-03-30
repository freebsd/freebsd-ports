# Created by: maurice
# $FreeBSD$

PORTNAME=	radiusclient
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/radiusclient-ng.berlios \
		http://download.berlios.de/radiusclient-ng/ \
		http://download2.berlios.de/radiusclient-ng/
DISTNAME=	${PORTNAME}-ng-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Client library and basic utilities for RADIUS AAA

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_LDCONFIG=	yes
ETCDIR=		${PREFIX}/etc/${PORTNAME}-ng

.include <bsd.port.mk>
