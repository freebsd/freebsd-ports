# New ports collection makefile for:    bidiv
# Date created:		06 Jan 2003
# Whom:			Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bidiv
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.ivrix.org.il/pub/ivrix/src/cmdline/
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	A bidirectional text filter

LIB_DEPENDS=	fribidi.3:${PORTSDIR}/converters/fribidi

WRKSRC=		${WRKDIR}/bidiv
MAN1=		bidiv.1
MAKE_ENV+=	CC_OPT_FLAGS="${CFLAGS}"

BROKEN=	needs update for the new fribidi paragraph API
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

post-patch:
	${REINPLACE_CMD} -E "s/^(PREFIX|CC_OPT_FLAGS).+//g;" ${WRKSRC}/Makefile

.include <bsd.port.mk>
