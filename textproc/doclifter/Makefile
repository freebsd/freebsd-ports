# ex:ts=8
# Ports collection makefile for:	doclifter
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	doclifter
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.catb.org/~esr/doclifter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translates documents written in troff macros to DocBook

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		doclifter.1
PLIST_FILES=	bin/doclifter

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
