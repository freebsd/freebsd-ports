# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	2.0.1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

PORTSCOUT=	limit:^2.*

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56
CONFLICTS=	pecl-xdiff-1*

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
