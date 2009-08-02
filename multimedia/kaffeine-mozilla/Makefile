# New ports collection makefile for:	kaffeine-mozilla
# Date created:				2004-05-25
# Whom:					arved
#
# $FreeBSD$
#   $MCom: ports-stable/multimedia/kaffeine-mozilla/Makefile,v 1.1 2008/08/01 23:13:21 mezz Exp $
#

PORTNAME=	kaffeine-mozilla
PORTVERSION=	0.2
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	SF/kaffeine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaffeine Mozilla plugin

RUN_DEPENDS=	kaffeine:${PORTSDIR}/multimedia/kaffeine

USE_XORG=	x11 xaw
USE_BZIP2=	yes
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=kaffeineplugin.so
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USE_AUTOTOOLS=	libtool:22

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	${REINPLACE_CMD} -e "s,[$$][(]prefix[)]/plugins,${WEBPLUGINS_DIR}," \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.post.mk>
