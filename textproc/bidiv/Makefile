# New ports collection makefile for:    bidiv
# Date created:		06 Jan 2003
# Whom:			Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bidiv
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.ivrix.org.il/pub/ivrix/src/cmdline/
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	A bidirectional text filter

LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/bidiv
MAN1=		bidiv.1
MAKE_ENV+=	CC_OPT_FLAGS="${CFLAGS}"

post-patch:
	${REINPLACE_CMD} -E "s/^(PREFIX|CC_OPT_FLAGS).+//g;" ${WRKSRC}/Makefile

.include <bsd.port.mk>
