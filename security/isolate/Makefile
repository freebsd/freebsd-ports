# New ports collection makefile for:	isolate
# Date created:		2010-01-05
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	isolate
PORTVERSION=	20100717
CATEGORIES=	security
MASTER_SITES=	http://meatwad.mouf.net/~steve/

MAINTAINER=	steve@mouf.net
COMMENT=	Runs processes in a restricted environment

PLIST_FILES=	bin/isolate
MAN1=		isolate.1
MANCOMPRESSED=	yes
USE_GMAKE=	yes
ALL_TARGET=	isolate

post-patch:
	        @${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700025
IGNORE=	does not compile (needs gelf.h)
.endif

.include <bsd.port.post.mk>
