# ex:ts=8
# Ports collection makefile for:	glark
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glark
PORTVERSION=	1.5.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Search text files for complex regular expressions

USE_RUBY=	yes
NO_BUILD=	yes

MAN1=	glark.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glark ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
