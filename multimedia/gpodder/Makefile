# Created by: Chess Griffin <chess@chessgriffin.com>
# $FreeBSD$

PORTNAME=	gpodder
PORTVERSION=	3.5.2
CATEGORIES=	multimedia python
MASTER_SITES=	http://gpodder.org/src/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Media aggregator and podcast client

LICENSE=	GPLv3

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.0.1:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}mygpoclient>=1.4:${PORTSDIR}/devel/py-mygpoclient \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0:${PORTSDIR}/audio/py-eyed3

OPTIONS_DEFINE=		GTK2 NOTIFY MUTAGEN OGG2MP3
OPTIONS_DEFAULT=	GTK2
MUTAGEN_DESC=		Allow metadata manipulation
OGG2MP3_DESC=		Ogg Vorbis conversion to MP3 support
OPTIONS_EXCLUDE=	NLS
NOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0:${PORTSDIR}/devel/py-notify
MUTAGEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen
OGG2MP3_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
			oggdec:${PORTSDIR}/audio/vorbis-tools

ALL_TARGET=	messages
MAKE_ENV=	GPODDER_MANPATH_NO_SHARE="yes"
MAKEFILE=	makefile
USES=		gettext gmake shebangfix
USE_PYTHON=	2
SHEBANG_FILES=	src/gpodder/*.py share/gpodder/examples/*.py share/gpodder/extensions/*.py
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
PORTDOCS=	PKG-INFO README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
MAKE_ENV+=	GPODDER_INSTALL_UIS="cli gtk"
PLIST_SUB+=	GTK=""
RUN_DEPENDS+=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		xdg-open:${PORTSDIR}/devel/xdg-utils
USE_GNOME=	pygtk2
.else
MAKE_ENV+=	GPODDER_INSTALL_UIS="cli"
PLIST_SUB+=	GTK="@comment "
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
