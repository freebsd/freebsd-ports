# New ports collection makefile for:	sendip
# Date created:				Wed 29 Nov 2000
# Whom:					joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=	sendip
PORTVERSION=	2.1
CATEGORIES=	net
MASTER_SITES=	http://www.earth.li/projectpurple/files/

MAINTAINER=	joseph@randomnetworks.com

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes

MAN1=		sendip.1

pre-install:
	${REINPLACE_CMD} -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e "s:/share/man/man1:/man/man1:g" ${WRKSRC}/Makefile;

.include <bsd.port.mk>
