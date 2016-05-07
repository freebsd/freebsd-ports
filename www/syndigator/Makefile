# Created by: ijliao
# $FreeBSD$
# $MCom: ports/www/syndigator/Makefile,v 1.4 2007/09/09 22:45:27 mezz Exp $

PORTNAME=	syndigator
PORTVERSION=	0.15.1
PORTREVISION=	10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Syndigator/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSS feed reader based on Gtk2

RUN_DEPENDS=	p5-Text-Iconv>=0:converters/p5-Text-Iconv \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-XML-RSS>=0:textproc/p5-XML-RSS \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww \
		p5-Gnome2>=0:x11-toolkits/p5-Gnome2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Html2>=0:x11-toolkits/p5-Gtk2-Html2

USES=		perl5 shebangfix
SHEBANG_FILES=	syndigator
NO_BUILD=	yes

GNOMEDIR=	${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|./lib|${PREFIX}/${SITE_PERL_REL}/${PORTNAME}|' \
		${WRKSRC}/syndigator
	@${REINPLACE_CMD} -i '' -e 's|./images/|${GNOMEDIR}/pixmaps/${PORTNAME}/|' \
		${WRKSRC}/lib/RSSReader/Gtk2UI/IconFactory.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/syndigator ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	cd ${WRKSRC}/lib && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${GNOMEDIR}/applications
	${INSTALL_DATA} ${WRKSRC}/syndigator.desktop ${STAGEDIR}${GNOMEDIR}/applications
	@${MKDIR} ${STAGEDIR}${GNOMEDIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.* ${STAGEDIR}${GNOMEDIR}/pixmaps
	@${MKDIR} ${STAGEDIR}${GNOMEDIR}/pixmaps/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${STAGEDIR}${GNOMEDIR}/pixmaps/${PORTNAME}

.include <bsd.port.mk>
