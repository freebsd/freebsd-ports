# New ports collection makefile for:	raggle
# Date created:				04 September 2003
# Whom:					gslin@ccca.nctu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	raggle
PORTVERSION=	0.2.4
CATEGORIES=	net
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A console RSS aggregator written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml yaml

NO_BUILD=	yes

MAN1=		raggle.1
DOCS=		AUTHORS BUGS COPYING ChangeLog README TODO doc/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/raggle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/raggle.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${DATADIR}/extras ${DATADIR}/themes
	${INSTALL_DATA} ${WRKSRC}/extras/* ${DATADIR}/extras
	${INSTALL_DATA} ${WRKSRC}/themes/* ${DATADIR}/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
