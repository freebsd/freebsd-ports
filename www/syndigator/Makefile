# ex:ts=8
# Ports collection Makefile for: 	syndigator
# Date created:			Apr 20, 2004
# Whom:				ijliao
#
# $FreeBSD$
#   $MCom: ports/www/syndigator/Makefile,v 1.4 2007/09/09 22:45:27 mezz Exp $
#

PORTNAME=	syndigator
PORTVERSION=	0.15.1
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Syndigator/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS feed reader based on Gtk2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Gnome2.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/Html2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2-Html2

USE_GNOME=	gnomehier
USE_PERL5=	yes
NO_BUILD=	yes

GNOMEDIR=	${PREFIX}/share

post-patch:
	@${PERL} -pi -e 's|./lib|${PREFIX}/${SITE_PERL_REL}/${PORTNAME}|g' \
		${WRKSRC}/syndigator
	@${PERL} -pi -e 's|./images/|${GNOMEDIR}/pixmaps/${PORTNAME}/|g' \
		${WRKSRC}/lib/RSSReader/Gtk2UI/IconFactory.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/syndigator ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	cd ${WRKSRC}/lib && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	@${MKDIR} ${GNOMEDIR}/applications
	${INSTALL_DATA} ${WRKSRC}/syndigator.desktop ${GNOMEDIR}/applications
	@${MKDIR} ${GNOMEDIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.* ${GNOMEDIR}/pixmaps
	@${MKDIR} ${GNOMEDIR}/pixmaps/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${GNOMEDIR}/pixmaps/${PORTNAME}

.include <bsd.port.mk>
