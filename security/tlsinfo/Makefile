PORTNAME=	tlsinfo
CATEGORIES=	security
DISTVERSION=    0.1.41
DISTVERSIONPREFIX=	v

MAINTAINER=	ports@paepcke.de
COMMENT=        Tool to analyze and troubleshoot TLS Connections
WWW=		https://paepcke.de/${PORTNAME}

LICENSE=	BSD3CLAUSE

USES=		go:modules

GO_MODULE=	paepcke.de/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME} 

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
