# New ports collection makefile for:    wv2
# Date created:         Do 28 Aug 2003 15:50:37 CEST
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	wv2
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	lofi@freebsd.org
COMMENT=	A library providing routines to access Microsoft Word files

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} --disable-debug

USE_GNOME=	gnometarget libgsf
USE_INC_LIBTOOL_VER=13
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

pre-configure:
	@${REINPLACE_CMD} "s,-pedantic ,," ${WRKSRC}/configure

.include <bsd.port.mk>
