# Created by: Florian Smeets <flo@smeets.im>
# $FreeBSD$

PORTNAME=	wbxml
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PECL extension that provides WBXML conversion capabilities

LIB_DEPENDS=	libwbxml2.so:textproc/wbxml2

USES=		php:ext tar:tgz

CONFIGURE_ARGS=	--with-wbxml=${LOCALBASE} \
		--with-libexpat-dir=${LOCALBASE}
IGNORE_WITH_PHP=	70

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
