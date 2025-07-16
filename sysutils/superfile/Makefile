PORTNAME=	superfile
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/MHNightCat/superfile

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.24

GO_MODULE=	github.com/MHNightCat/superfile

PLIST_FILES=	bin/superfile bin/spf

post-install:
	${LN}	${STAGEDIR}${PREFIX}/bin/superfile ${STAGEDIR}${PREFIX}/bin/spf

.include <bsd.port.mk>
