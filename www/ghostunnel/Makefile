PORTNAME=	ghostunnel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.4
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SSL/TLS proxy with mutual authentication for securing non-TLS services
WWW=		https://github.com/ghostunnel/ghostunnel

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/ghostunnel/ghostunnel

PLIST_FILES=	bin/ghostunnel

.include <bsd.port.mk>
