PORTNAME=	gobuster
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
PORTREVISION=	16
CATEGORIES=	misc dns www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory/file & DNS busting tool written in Go
WWW=		https://github.com/OJ/gobuster

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/OJ/gobuster/v3
GO_TARGET=	.

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
