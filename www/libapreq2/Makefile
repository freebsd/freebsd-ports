# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	libapreq2
PORTVERSION=	2.13
PORTREVISION=	5
CATEGORIES=	www devel
MASTER_SITES=	APACHE_HTTPD/libapreq

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Generic Apache2 Request Library

LICENSE=	APACHE20

USES=		libtool
USE_APACHE=	22+
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}

SHLIB_MAJOR=	11
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libapreq2.so.3.8.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_apreq2.so

.include <bsd.port.mk>
