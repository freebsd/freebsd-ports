# New ports collection makefile for:	libwww
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	libwww
PORTVERSION=	5.4.0
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/
DISTNAME=	w3c-${PKGNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The W3C Reference Library

USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static --with-zlib
MAKE_ENV=	objformat=${PORTOBJFORMAT}

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/expat/xmlparse/xmlparse.h \
		${PREFIX}/include/w3c-libwww/

.include <bsd.port.mk>
