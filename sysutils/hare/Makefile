PORTNAME=	hare
DISTVERSION=	1.1
CATEGORIES=	sysutils

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Small C client for sending ssh login notications to a hared server
WWW=		https://github.com/jpmens/hared-hare

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jpmens
GH_PROJECT=	hared-hare

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
