# New ports collection makefile for:	slrnconf
# Date created:				13 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	slrnconf
PORTVERSION=	0.8.2
CATEGORIES=	news
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Graphical configuation utility for the newsreader slrn

BUILD_DEPENDS=	slrn:${PORTSDIR}/news/slrn \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent

USE_REINPLACE=	yes

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
	's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/${file}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/help
	@${INSTALL_DATA} ${WRKSRC}/help/* \
		${PREFIX}/share/${PORTNAME}/help
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/data
	@${INSTALL_DATA} ${WRKSRC}/data/* \
		${PREFIX}/share/${PORTNAME}/data
	@${INSTALL_SCRIPT} ${WRKSRC}/slrnconf \
		${PREFIX}/bin
.for i in ABOUT COPYING README preferences.pm rc_grammar.pm ui.pm
	@${INSTALL_DATA} ${WRKSRC}/${i} \
		${PREFIX}/share/${PORTNAME}
.endfor

.include <bsd.port.mk>
