# ex:ts=8
# Ports collection makefile for:	netspoc
# Date created:			Nov 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netspoc
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/netspoc/

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	netspoc.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netspoc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/netspoc.man ${MANPREFIX}/man/man1/netspoc.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
