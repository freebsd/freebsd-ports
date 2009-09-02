# New ports collection makefile for:   xmms-weasel
# Date created:        4 April 2004
# Whom:                Narayan Newton <narayan_newton@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-weasel
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/XMMS%20Weasel%20v${PORTVERSION}

MAINTAINER=	narayannewton@gmail.com
COMMENT=	A XMMS plugin to hide the player

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/General/libweasel.la \
		lib/xmms/General/libweasel.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
