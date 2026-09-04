PORTNAME=	blockio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Display block device activity as a map of the address space
WWW=		https://github.com/olgeni/blockio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/blockio

PLIST_FILES=	bin/blockio \
		share/man/man8/blockio.8.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/blockio.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
