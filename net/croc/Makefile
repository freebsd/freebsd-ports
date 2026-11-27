PORTNAME=	croc
DISTVERSIONPREFIX=	v
DISTVERSION=	11.6.7
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders
WWW=		https://github.com/schollz/croc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	schollz
USE_RC_SUBR=	croc

GO_MODULE=	github.com/schollz/croc/v11

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
