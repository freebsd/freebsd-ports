# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	2.0.1
CATEGORIES=	textproc pear

# https://github.com/php/pecl-text-xdiff/pull/5/
PATCH_SITES=	https://github.com/php/pecl-text-xdiff/commit/
PATCHFILES=	b9aec331034f90998e31c60166b5caf758896584.patch:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

USES=		php:pecl
CONFLICTS=	pecl-xdiff-1*

LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
