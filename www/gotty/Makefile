PORTNAME=	gotty
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	www net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line tool that turns your CLI tools into web applications
WWW=		https://github.com/sorenisanerd/gotty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sorenisanerd

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gotty

.include <bsd.port.mk>
