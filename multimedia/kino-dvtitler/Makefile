# New ports collection makefile for:	kino-dvtitler
# Date created:				1 May 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	kino-dvtitler
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/kino-//}
DISTNAME=	${PORTNAME:S/kino-//}-${PORTVERSION}

MAINTAINER=	mad@madpilot.net
COMMENT=	Titler plugin for the kino DV editor

BUILD_DEPENDS=	kino:${PORTSDIR}/multimedia/kino
RUN_DEPENDS=	kino:${PORTSDIR}/multimedia/kino

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/src/textblock.cc

.include <bsd.port.mk>
