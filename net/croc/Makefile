PORTNAME=	croc
PORTVERSION=	10.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders
WWW=		https://github.com/schollz/croc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	croc

GO_MODULE=	github.com/schollz/croc/v10

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
