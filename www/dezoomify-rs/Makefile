PORTNAME=	dezoomify-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.15.0
PORTREVISION=	11
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Zoomable image downloader
WWW=		https://dezoomify-rs.ophir.dev/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	lovasoa

PLIST_FILES=	bin/dezoomify-rs

.include <bsd.port.mk>
