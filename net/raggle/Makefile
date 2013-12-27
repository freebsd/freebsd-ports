# Created by: gslin@ccca.nctu.edu.tw
# $FreeBSD$

PORTNAME=	raggle
PORTVERSION=	0.4.4
CATEGORIES=	net
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A console RSS aggregator written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml yaml

NO_BUILD=	yes

MAN1=		raggle.1
DOCS=		AUTHORS BUGS COPYING ChangeLog README TODO \
		doc/default_config.rb doc/pauls_feeds.opml.gz \
		doc/theme_documentation.txt

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/raggle ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/themes \
	${STAGEDIR}${DATADIR}/extras/web_ui/images \
	${STAGEDIR}${DATADIR}/extras/web_ui/inc ${STAGEDIR}${DATADIR}/extras/win32
	${INSTALL_DATA} ${WRKSRC}/extras/*.rb ${STAGEDIR}${DATADIR}/extras
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/*.html \
	${STAGEDIR}${DATADIR}/extras/web_ui
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/images/* \
	${STAGEDIR}${DATADIR}/extras/web_ui/images
	${INSTALL_DATA} ${WRKSRC}/extras/web_ui/inc/* \
	${STAGEDIR}${DATADIR}/extras/web_ui/inc
	${INSTALL_DATA} ${WRKSRC}/extras/win32/* ${STAGEDIR}${DATADIR}/extras/win32
	${INSTALL_DATA} ${WRKSRC}/themes/* ${STAGEDIR}${DATADIR}/themes
.if ${PORT_OPTIONS:MDOCS} 
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
