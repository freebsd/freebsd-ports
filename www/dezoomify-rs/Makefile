PORTNAME=	dezoomify-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.4
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Zoomable image downloader
WWW=		https://dezoomify-rs.ophir.dev/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	lovasoa

PLIST_FILES=	bin/dezoomify-rs

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
