# New ports collection makefile for:   dhcpdump
# Date created:        1 March 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=      dhcpdump
PORTVERSION=   1.1
CATEGORIES=    net
MASTER_SITES=  http://www.mavetju.org/download/

MAINTAINER=    edwin@mavetju.org

MAN1=		dhcpdump.1

pre-build:
	${PERL} -pi -e "s@gcc@${CC}@g; \
			s@-Wall -g@-Wall ${CFLAGS}@g; \
			s@/usr/local@${PREFIX}@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
