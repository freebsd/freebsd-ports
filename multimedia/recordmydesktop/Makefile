PORTNAME=	recordmydesktop
DISTVERSION=	0.3.8.1
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Record desktop sessions to an Ogg-Theora-Vorbis file

LICENSE=	GPLv2+

LIB_DEPENDS=	libtheora.so:multimedia/libtheora

USES=		xorg
USE_XORG=	ice sm x11 xdamage xext xfixes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oss=yes

PLIST_FILES=	bin/recordmydesktop man/man1/recordmydesktop.1.gz
PORTDOCS=	ChangeLog

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--enable-jack=no

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
