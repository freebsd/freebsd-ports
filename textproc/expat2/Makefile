# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	expat

MAINTAINER=	kuriyama@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
USE_LIBTOOL=	yes
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

SHLIB_MAJOR=	2

MAKE_ARGS=	LIBCURRENT="${SHLIB_MAJOR}"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlwf/xmlwf ${PREFIX}/bin

.include <bsd.port.mk>
