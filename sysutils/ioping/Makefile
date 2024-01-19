PORTNAME=	ioping
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple disk I/0 latency measuring tool
WWW=		https://github.com/koct9i/ioping

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

PLIST_FILES=	bin/ioping \
		share/man/man1/ioping.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	koct9i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
