PORTNAME=	croc
PORTVERSION=	10.0.13
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders
WWW=		https://github.com/schollz/croc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/schollz/croc/v10

USE_RC_SUBR=	croc

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
