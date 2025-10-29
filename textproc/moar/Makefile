PORTNAME=	moar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.31.3
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pager designed to just do the right thing without any configuration
WWW=		https://github.com/walles/moar

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream renamed to moor, use textproc/moor instead.
EXPIRATION_DATE=	2025-11-30

USES=		go:1.20,modules

GO_MODULE=	github.com/walles/moar

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
