# Created by: Florian Smeets <flo@smeets.im>
# $FreeBSD$

PORTNAME=	wbxml
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	textproc pear

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PECL extension that provides WBXML conversion capabilities

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libwbxml2.so:textproc/wbxml2

USES=		php:pecl

CONFIGURE_ARGS=	--with-wbxml=${LOCALBASE} \
		--with-libexpat-dir=${LOCALBASE}
IGNORE_WITH_PHP=	71 72 73

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
