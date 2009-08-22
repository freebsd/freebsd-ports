# New ports collection makefile for:	tv rss
# Date created:		Sat Sep 30 01:40:54 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tvrss
DISTVERSION=	1.8beta
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	SF/tvtrss/TV%20RSS/TV%20RSS%201.8beta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Torrent RSS feed reader

RUN_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/Gdk/Keysyms.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/SimpleList.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/XML/RAI.pm:${PORTSDIR}/textproc/p5-XML-RAI \
		wget:${PORTSDIR}/ftp/wget

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	\
		bin/${PORTNAME} \
		%%DATADIR%%/${PORTNAME}.png
PLIST_DIRS=	\
		%%DATADIR%%

DESKTOP_ENTRIES=	"TV RSS" \
			"Torrent RSS feed reader" \
			"${DATADIR}/tvrss.png" \
			"tvrss" \
			"Application;P2P;Network;" \
			true

# RSS feeds
RSS_FEED_EZTV=	http://tvrss.net/feed/eztv/
RSS_FEED_VTV=	http://tvrss.net/feed/vtv/

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}
# rss feed source update
	@${REINPLACE_CMD} -E \
		-e 's|http://tvrss.net/sources/eztv/|${RSS_FEED_EZTV}|' \
		-e 's|http://tvrss.net/sources/vtv/|${RSS_FEED_VTV}|' \
		${WRKSRC}/${PORTNAME}

do-install:
# icons
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${DATADIR}
# scripts
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
