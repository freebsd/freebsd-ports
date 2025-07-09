PORTNAME=	s5cmd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	5
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Very fast S3 command-line tool written in Go
WWW=		https://github.com/peak/s5cmd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	peak

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/s5cmd

.include <bsd.port.mk>
