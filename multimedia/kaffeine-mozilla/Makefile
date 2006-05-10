# New ports collection makefile for:	kaffeine-mozilla
# Date created:				2004-05-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine-mozilla
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaffeine Mozilla plugin

RUN_DEPENDS=	kaffeine:${PORTSDIR}/multimedia/kaffeine

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"
USE_XLIB=	yes
USE_X_PREFIX=	yes

post-patch:
	${REINPLACE_CMD} -e "s,prefix)/plugins,prefix)/lib/browser_plugins," ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
