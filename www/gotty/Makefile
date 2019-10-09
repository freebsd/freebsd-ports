# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gotty
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line tool that turns your CLI tools into web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	yudai

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gotty

.include <bsd.port.mk>
