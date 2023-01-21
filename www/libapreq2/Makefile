PORTNAME=	libapreq2
PORTVERSION=	2.13
PORTREVISION=	5
CATEGORIES=	www devel
MASTER_SITES=	APACHE_HTTPD/libapreq

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Generic Apache2 Request Library
WWW=		https://metacpan.org/dist/libapreq2

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		apache cpe libtool
CPE_VENDOR=	apache
USE_LDCONFIG=	yes

.include <bsd.port.mk>
