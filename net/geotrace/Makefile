# ex:ts=8
# New ports collection makefile for:	geotrace
# Date created:			Apr 19, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geotrace
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Graphical traceroute utility

USE_GNOME=	gdkpixbuf libcapplet

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/prefs.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/geotrace ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/maps
	${CP} -R ${WRKSRC}/maps/ ${PREFIX}/etc/maps

.include <bsd.port.mk>
