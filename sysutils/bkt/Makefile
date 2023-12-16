PORTNAME=	bkt
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Subprocess caching utility
WWW=		https://github.com/dimo414/bkt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dimo414

PLIST_FILES=	bin/bkt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bkt

.include <bsd.port.mk>
