# New ports collection makefile for:	rtfx
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	rtfx
PORTVERSION=	0.9.3
CATEGORIES=	textproc
MASTER_SITES=	http://memberwebs.com/nielsen/software/rtfx/

MAINTAINER=	clsung@dragon2.net
COMMENT=	An RTF to XML converter

LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		rtfx.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500035
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src::domhelpers.h-gcc295
.endif

.include <bsd.port.post.mk>
