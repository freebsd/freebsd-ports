# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	esmtp
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL ESMTP client extension

LICENSE=	PHP30

LIB_DEPENDS=	libesmtp.so:mail/libesmtp

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	56 70

OPTIONS_DEFINE=	RE2C
OPTIONS_DEFAULT=	RE2C
RE2C_DESC=	Use re2c to regenerate PHP parsers

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRE2C}
BUILD_DEPENDS+=	re2c:devel/re2c
.endif

post-patch:
	@${REINPLACE_CMD} -e '29,34 d; 45,50 d' ${WRKSRC}/config.m4

.include <bsd.port.mk>
