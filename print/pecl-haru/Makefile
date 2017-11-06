# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	haru
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	print pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PECL extension to Haru PDF functions

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/hpdf.h:print/libharu
RUN_DEPENDS:=	${LOCALBASE}/include/hpdf.h:print/libharu

USES=		php:pecl
IGNORE_WITH_PHP=	70 71

CONFIGURE_ARGS+=	--with-haru=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
