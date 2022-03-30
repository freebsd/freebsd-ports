# Created by: Toni Gundogdu <legatvs@gmail.com>

PORTNAME=	quvi
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/quvi/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool for parsing flash media stream URLs

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libquvi>=0.4.0:multimedia/libquvi
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libquvi.so:multimedia/libquvi

USES=		pkgconfig tar:xz

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/quvi \
		man/man1/quvi.1.gz

PORTSCOUT=	limit:^0\.4\.

.include <bsd.port.mk>
