# ex:ts=8
# New ports collection makefile for:	txt2man
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2man
PORTVERSION=	1.4.1
CATEGORIES=	textproc
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ijliao@FreeBSD.org

ALL_TARGET=	txt2man.1

MAN1=	txt2man.1

post-patch:
	@${PERL} -pi -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
