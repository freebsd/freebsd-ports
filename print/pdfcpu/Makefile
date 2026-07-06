PORTNAME=	pdfcpu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	print

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	PDF processor written in Go
WWW=		https://github.com/pdfcpu/pdfcpu

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:1.25+,modules

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

PLIST_FILES=	bin/pdfcpu

GO_LDFLAGS=	-X main.commit=Release \
		-X main.date=tagged
GO_TARGET=	./cmd/${PORTNAME}

.include <bsd.port.mk>
