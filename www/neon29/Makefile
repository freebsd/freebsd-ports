# New ports collection makefile for: neon
# Date created:		13 October 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neon
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat \
		xml:${PORTSDIR}/textproc/libxml

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --with-expat=${PREFIX}/include/xml \
		--with-extra-libs=${PREFIX}/lib

ALL_TARGET=	all
INSTALL_TARGET=	install

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/neon
	${INSTALL_DATA} ${WRKSRC}/doc/using-neon.txt ${PREFIX}/share/doc/neon
.endif

.include <bsd.port.mk>
