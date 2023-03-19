PORTNAME=	libapreq2
PORTVERSION=	2.17
PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	APACHE_HTTPD/libapreq

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Generic Apache2 Request Library
WWW=		https://metacpan.org/dist/libapreq2

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libaprutil-1.so:devel/apr1 \
		libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		apache cpe libtool
CPE_VENDOR=	apache
USE_LDCONFIG=	yes

.include <bsd.port.mk>
