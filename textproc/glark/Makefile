# ex:ts=8
# Ports collection makefile for:	glark
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glark
PORTVERSION=	1.7.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.incava.org/pub/glark/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Search text files for complex regular expressions

USE_RUBY=	yes
NO_BUILD=	yes

MAN1=		glark.1
PLIST_FILES=	bin/glark

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glark ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
