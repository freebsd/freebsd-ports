PORTNAME=	ipget
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Retrieve files over IPFS and save them locally
WWW=		https://github.com/ipfs/ipget

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25,modules

GO_MODULE=	github.com/ipfs/ipget

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
