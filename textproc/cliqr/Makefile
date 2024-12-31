PORTNAME=	cliqr
CATEGORIES=	textproc
DISTVERSION=    0.1.25
DISTVERSIONPREFIX=	v

MAINTAINER=	ports@paepcke.de
COMMENT=        Tool to generate and display QR in the command line
WWW=		https://paepcke.de/${PORTNAME}

LICENSE=	BSD3CLAUSE

USES=		go:modules

GO_MODULE=	paepcke.de/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME} 

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
