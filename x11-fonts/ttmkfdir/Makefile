# New ports collection makefile for:	ttmkfdir
# Date created:		September 08, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttmkfdir
PORTVERSION=	20021109
PORTREVISION=	1
CATEGORIES=	x11-fonts x11
MASTER_SITES=	http://people.redhat.com/yshao/
DISTNAME=	${PORTNAME}2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create fonts.scale file for use with TrueType font server

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

WANT_LIBTOOL_VER=13
PLIST_FILES=	bin/ttmkfdir
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include <bsd.port.mk>
