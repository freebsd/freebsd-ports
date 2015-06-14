# Created by: Thomas-Martin Seck <tmseck@web.de>
# $FreeBSD$

PORTNAME=	libecap
PORTVERSION=	1.0.1
CATEGORIES=	www security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for module based network content analysis

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool

.include <bsd.port.mk>
