# ex:ts=8
# Ports collection makefile for:  phraze
# Date created:                   Wed Apr 16, 2003
# Whom:                           Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	phraze
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Converts telephone number to combinations of valid words

USE_RUBY=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/ruby|#!${RUBY}|; \
	s|/usr/local/phraze|${DATADIR}|' ${WRKSRC}/phraze ${WRKSRC}/phraze.1

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/phraze.dict ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/phraze ${PREFIX}/bin/phraze
	${INSTALL_MAN} ${WRKSRC}/phraze.1 ${PREFIX}/man/man1/

MAN1=		phraze.1

.include <bsd.port.mk>
