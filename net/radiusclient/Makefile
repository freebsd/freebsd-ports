PORTNAME=	radiusclient
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/radiusclient-ng.berlios
DISTNAME=	${PORTNAME}-ng-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client library and basic utilities for RADIUS AAA
WWW=		http://developer.berlios.de/projects/radiusclient-ng/

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe gmake libtool
USE_LDCONFIG=	yes
ETCDIR=		${PREFIX}/etc/${PORTNAME}-ng

.include <bsd.port.mk>
