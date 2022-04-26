# Created by: Toni Gundogdu <legatvs@gmail.com>

PORTNAME=	cclive
PORTVERSION=	0.7.16
PORTREVISION=	12
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight command line video extraction tool

LICENSE=	GPLv3

BROKEN=		Multiple bug reports upstream
DEPRECATED=	Last release in 2013, please consider using www/yt-dlp or multimedia/streamlink
EXPIRATION_DATE=2022-06-30

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libquvi.so:multimedia/libquvi

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}

CONFLICTS_INSTALL=	ccl # bin/clive

PLIST_FILES=	bin/ccl \
		bin/cclive \
		man/man1/cclive.1.gz

.include <bsd.port.mk>
