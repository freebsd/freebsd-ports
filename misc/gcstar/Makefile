# Created by: Dominique Goncalves <dominique.goncalves@gmail.com>
# $FreeBSD$

PORTNAME=	gcstar
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/gcstar/ \
		http://djdomics.free.fr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source application for managing your collections

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-libwww>=0:www/p5-libwww \
		p5-MP3-Info>=0:audio/p5-MP3-Info \
		p5-MP3-Tag>=0:audio/p5-MP3-Tag \
		p5-Ogg-Vorbis-Header-PurePerl>=0:audio/p5-Ogg-Vorbis-Header-PurePerl \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Time-Piece>=0:devel/p5-Time-Piece \
		p5-Gtk2-Spell>=0:devel/p5-Gtk2-Spell \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Switch>0:lang/p5-Switch \
		p5-Gnome2-VFS>=0:x11-toolkits/p5-Gnome2-VFS \
		p5-Net-FreeDB>=0:audio/p5-Net-FreeDB \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally \
		p5-GD>=0:graphics/p5-GD \
		p5-GD-Graph>=0:graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:graphics/p5-GD-TextUtil

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		perl5 desktop-file-utils shared-mime-info shebangfix
SHEBANG_FILES=	bin/gcstar
USE_PERL5=	run
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	@${FIND} ${WRKSRC}/ -name '*.orig' -delete
	${PERL} ${WRKSRC}/install --prefix ${STAGEDIR}${PREFIX} --noclean
	${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.desktop \
		${STAGEDIR}${PREFIX}/share/applications/gcstar.desktop
	${INSTALL_DATA} ${WRKSRC}/share/applications/gcstar.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/gcstar.xml
	${INSTALL_DATA} ${WRKSRC}/share/gcstar/icons/gcstar_48x48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gcstar.png

.include <bsd.port.mk>
