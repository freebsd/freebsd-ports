# ex:ts=8
# New ports collection makefile for:	gman
# Date created:			Mar 30, 3001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gman
PORTVERSION=	0.9.0
CATEGORIES=	misc
MASTER_SITES=	http://homex.coolconnect.com/user/xkwang/gman/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview

USE_GTK=	yes

MAN1=	gman.1x

post-patch:
	@${PERL} -pi -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
