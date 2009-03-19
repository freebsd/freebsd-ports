# New ports collection makefile for: gcstar
# Date created: 	2007-12-22
# Whom:         	Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$

PORTNAME=	gcstar
PORTVERSION=	1.4.3
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/gcstar/ \
		http://djdomics.free.fr/distfiles/

MAINTAINER=	dominique.goncalves@gmail.com
COMMENT=	Open source application for managing your collections

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-MP3-Tag \
		${SITE_PERL}/Ogg/Vorbis/Header/PurePerl.pm:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header-PurePerl \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/Spell.pm:${PORTSDIR}/devel/p5-Gtk2-Spell \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		${SITE_PERL}/${PERL_ARCH}/Net/FreeDB.pm:${PORTSDIR}/audio/p5-Net-FreeDB

MAN1=		gcstar.1
MANCOMPRESSED=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5_RUN=	yes

NO_BUILD=	yes

do-install:
		@${MKDIR} ${PREFIX}/share/mime/application
		@${MKDIR} ${PREFIX}/share/pixmaps
		@${MKDIR} ${PREFIX}/share/applications
		@${FIND} ${WRKSRC}/ -name '*.orig' -delete
		${PERL} ${WRKSRC}/install --prefix ${PREFIX}
		${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.desktop \
			${PREFIX}/share/applications/gcstar.desktop
		${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.xml \
			${PREFIX}/share/mime/application/gcstar.xml
		${INSTALL_DATA} ${WRKSRC}/share/gcstar/icons/gcstar_48x48.png \
			${PREFIX}/share/pixmaps/gcstar.png

.include <bsd.port.mk>
