# New ports collection makefile for:	slrnconf
# Date created:				13 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	slrnconf
PORTVERSION=	0.8.4
CATEGORIES=	news
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical configuation utility for the newsreader slrn

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent

USE_BZIP2=	yes
USE_PERL=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

do-install:
	@${MKDIR} ${DATADIR}/help
	@${INSTALL_DATA} ${WRKSRC}/help/* ${DATADIR}/help
	@${MKDIR} ${DATADIR}/data
	@${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/data
	@${INSTALL_SCRIPT} ${WRKSRC}/slrnconf ${PREFIX}/bin
.for i in preferences.pm rc_grammar.pm ui.pm
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ABOUT COPYING README
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
