# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	cclive
PORTVERSION=	0.7.11
PORTREVISION=	3
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/0.7 \
		GOOGLE_CODE

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Lightweight command line video extraction tool

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libquvi.so:${PORTSDIR}/multimedia/libquvi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-boost=${LOCALBASE}
USES=		pkgconfig
USE_XZ=		yes

MAN1=		cclive.1
PLIST_FILES=	bin/ccl \
		bin/cclive

NO_STAGE=	yes
.include <bsd.port.mk>
