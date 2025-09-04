PORTNAME=	goreplay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTREVISION=	22
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for capturing and replaying live HTTP traffic
WWW=		https://goreplay.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/buger/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
