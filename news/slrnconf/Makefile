# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	slrnconf
PORTVERSION=	0.8.4
PORTREVISION=	5
CATEGORIES=	news
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical configuration utility for the newsreader slrn

BUILD_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

USE_BZIP2=	yes
USES=		perl5
MAKE_ARGS+=	PREFIX=${PREFIX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${STAGEDIR}${DATADIR}/help
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/slrnconf ${STAGEDIR}${PREFIX}/bin
.for i in preferences.pm rc_grammar.pm ui.pm
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ABOUT COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
