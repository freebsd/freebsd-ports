# New ports collection makefile for: autorespond
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autorespond
PORTVERSION=	2.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

MAINTAINER=	roam@FreeBSD.org

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 440003 || ${OSVERSION} >= 500000 && ${OSVERSION} < 500027
CFLAGS+=	-DNEED_STRCASESTR
.endif

post-patch:
	${REINPLACE_CMD} -Ee "s|^(DEFS =.*)|\1 ${CFLAGS}|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin/

.include <bsd.port.post.mk>
