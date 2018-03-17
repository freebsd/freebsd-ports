# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	2.0.1
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	56

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

USES=		php:pecl
CONFLICTS=	pecl-xdiff-1*

LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
