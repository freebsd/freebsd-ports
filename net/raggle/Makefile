# New ports collection makefile for:	raggle
# Date created:				04 September 2003
# Whom:					gslin@ccca.nctu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	raggle
PORTVERSION=	0.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	ports@FreeBSD.org
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
	@${MKDIR} ${DATADIR}/themes ${DATADIR}/extras/web_ui/images \
		${DATADIR}/extras/web_ui/inc ${DATADIR}/extras/win32
	${INSTALL_DATA} ${WRKSRC}/extras/*.rb ${DATADIR}/extras
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/*.html ${DATADIR}/extras/web_ui
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/images/* ${DATADIR}/extras/web_ui/images
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/inc/* ${DATADIR}/extras/web_ui/inc
	${INSTALL_DATA} ${WRKSRC}/extras/win32/* ${DATADIR}/extras/win32
	${INSTALL_DATA} ${WRKSRC}/themes/* ${DATADIR}/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
