# Created by: Dominique Goncalves <dominique.goncalves@gmail.com>
# $FreeBSD$

PORTNAME=	gcstar
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/gcstar/ \
		http://djdomics.free.fr/distfiles/

MAINTAINER=	dominique.goncalves@gmail.com
COMMENT=	Open source application for managing your collections

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-MP3-Tag>=0:${PORTSDIR}/audio/p5-MP3-Tag \
		p5-Ogg-Vorbis-Header-PurePerl>=0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header-PurePerl \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Gtk2-Spell>=0:${PORTSDIR}/devel/p5-Gtk2-Spell \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Switch>0:${PORTSDIR}/lang/p5-Switch \
		p5-Gnome2-VFS>=0:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		p5-Net-FreeDB>=0:${PORTSDIR}/audio/p5-Net-FreeDB \
		p5-Sort-Naturally>=0:${PORTSDIR}/textproc/p5-Sort-Naturally \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil

MAN1=		gcstar.1
MANCOMPRESSED=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	desktopfileutils
USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
		@${MKDIR} ${PREFIX}/share/mime/packages
		@${FIND} ${WRKSRC}/ -name '*.orig' -delete
		${PERL} ${WRKSRC}/install --prefix ${PREFIX} --noclean
		${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.desktop \
			${PREFIX}/share/applications/gcstar.desktop
		${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.xml \
			${PREFIX}/share/mime/packages/gcstar.xml
		${INSTALL_DATA} ${WRKSRC}/share/gcstar/icons/gcstar_48x48.png \
			${PREFIX}/share/pixmaps/gcstar.png

post-install:
		-@update-desktop-database

.include <bsd.port.mk>
