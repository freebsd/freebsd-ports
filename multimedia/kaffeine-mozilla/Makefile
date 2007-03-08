# New ports collection makefile for:	kaffeine-mozilla
# Date created:				2004-05-25
# Whom:					arved
#
# $FreeBSD$
#    $MCom: ports/multimedia/kaffeine-mozilla/Makefile,v 1.3 2006/10/08 16:54:34 mezz Exp $
#

PORTNAME=	kaffeine-mozilla
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaffeine Mozilla plugin

RUN_DEPENDS=	kaffeine:${PORTSDIR}/multimedia/kaffeine

USE_XLIB=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"
USE_AUTOTOOLS=	libtool:15

post-patch:
	${REINPLACE_CMD} -e "s,prefix)/plugins,prefix)/lib/browser_plugins," ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
