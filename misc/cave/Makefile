# ex:ts=8
# Ports collection makefile for:	cave
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cave
PORTVERSION=	0.6
CATEGORIES=	misc
MASTER_SITES=	http://cyclic.sourceforge.net/cave/

MAINTAINER=	ports@FreeBSD.org

MANCOMPRESSED=	yes
MAN1=	cave.1

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,^PREFIX,#PREFIX,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
