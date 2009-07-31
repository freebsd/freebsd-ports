# New ports collection makefile for:    wv2
# Date created:         Do 28 Aug 2003 15:50:37 CEST
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	wv2
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/wvware

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library providing routines to access Microsoft Word files

CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} --disable-debug

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnometarget libgsf
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} "s,-pedantic ,," ${WRKSRC}/configure

.include <bsd.port.mk>
