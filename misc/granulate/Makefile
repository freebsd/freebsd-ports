# ex:ts=8
# New ports collection makefile for:   granulate
# Date created:			Feb 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	granulate
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	http://exe2bin.com/granulate/

MAINTAINER=	ports@FreeBSD.org

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
