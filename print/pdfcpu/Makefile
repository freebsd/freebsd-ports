PORTNAME=	pdfcpu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
CATEGORIES=	print

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	PDF processor written in Go
WWW=		https://github.com/pdfcpu/pdfcpu

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

PLIST_FILES=	bin/pdfcpu

CGO_ENABLED=	0
GO_LDFLAGS=	-X main.commit=Release \
		-X main.date=Tagged
GO_TARGET=	./cmd/${PORTNAME}

.include <bsd.port.mk>
