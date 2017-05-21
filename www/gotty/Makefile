# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gotty
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www net ipv6

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line tool that turns your CLI tools into web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yudai

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gotty

.include <bsd.port.mk>
