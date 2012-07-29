# Ports collection makefile for:  pecl-esmtp
# Date created:			  2006/08/01
# Whom:				  chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	esmtp
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL ESMTP client extension

LIB_DEPENDS=	esmtp:${PORTSDIR}/mail/libesmtp

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53

OPTIONS=	RE2C	"Enable re2c to regenerate PHP parsers"	on

.include <bsd.port.pre.mk>

.if defined(WITH_RE2C)
BUILD_DEPENDS+=	re2c:${PORTSDIR}/devel/re2c
.endif

post-patch:
	@${REINPLACE_CMD} -e '29,34 d; 45,50 d' ${WRKSRC}/config.m4

.include <bsd.port.post.mk>
