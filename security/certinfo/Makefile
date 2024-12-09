PORTNAME=	certinfo
CATEGORIES=	security
DISTVERSION=    0.1.36
DISTVERSIONPREFIX=	v

MAINTAINER=	ports@paepcke.de
COMMENT=        Tool to analyze x509, ssh and other certificates
WWW=		https://paepcke.de/${PORTNAME}

LICENSE=	BSD3CLAUSE

USES=		go:modules

GO_MODULE=	paepcke.de/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME} 

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
