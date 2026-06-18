PORTNAME=	superfile
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1-0.20260618150422
DISTVERSIONSUFFIX=	-5845124b77cd
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/yorukot/superfile

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_MODULE=	github.com/yorukot/superfile

PLIST_FILES=	bin/superfile bin/spf

post-install:
	${LN}	${STAGEDIR}${PREFIX}/bin/superfile ${STAGEDIR}${PREFIX}/bin/spf

.include <bsd.port.mk>
