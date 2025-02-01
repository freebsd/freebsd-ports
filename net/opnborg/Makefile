PORTNAME=	opnborg
CATEGORIES=	net
DISTVERSION=    0.1.18
DISTVERSIONPREFIX=	v

MAINTAINER=	ports@paepcke.de
COMMENT=        Selfhost-able OPNSense Appliance Configuration, Backup Portal
WWW=		https://paepcke.de/${PORTNAME}

LICENSE=	BSD3CLAUSE

USES=		go:modules

GO_MODULE=	paepcke.de/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME} 

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
