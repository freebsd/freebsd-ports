# New ports collection makefile for: neon
# Date created:		13 October 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neon
PORTVERSION=	0.12.0
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} \
		--enable-xml

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/neon
	${INSTALL_DATA} ${WRKSRC}/doc/using-neon.txt ${PREFIX}/share/doc/neon
.endif

.include <bsd.port.mk>
