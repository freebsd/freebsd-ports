# New ports collection makefile for:	webredirect
# Date created:		24 October 2000
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	webredirect
PORTVERSION= 	0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.Raditex.se/pub/kaj/

MAINTAINER=	kaj@Raditex.se

MAN1=		webredirect.1

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webredirect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webredirect.1 ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
