# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	2.0.1
CATEGORIES=	textproc pear
PKGNAMESUFFIX=	2

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

PORTSCOUT=	limit:^2.*

USES=		php:pecl
IGNORE_WITH_PHP=	56
CONFLICTS=	pecl-xdiff-1*

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
