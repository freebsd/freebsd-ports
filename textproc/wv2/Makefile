# New ports collection makefile for:    wv2
# Date created:         Do 28 Aug 2003 15:50:37 CEST
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	wv2
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	lofi@freebsd.org
COMMENT=	A library providing routines to access Microsoft Word/Excel files

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} --disable-debug

USE_GNOME=	gnometarget libgsf
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# none, we want to keep libwv2.la
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

pre-configure:
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} "s,-pedantic ,," ${WRKSRC}/configure

.include <bsd.port.mk>
