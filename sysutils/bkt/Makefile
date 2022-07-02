# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	bkt
PORTVERSION=	0.5.4
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Subprocess caching utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dimo414

PLIST_FILES=	bin/bkt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bkt

.include <bsd.port.mk>
