# Created by: Chess Griffin <chess@chessgriffin.com>
# $FreeBSD$

PORTNAME=	gpodder
PORTVERSION=	3.4.0
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
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus

OPTIONS_DEFINE=	GTK2 NOTIFY MUTAGEN OGG2MP3
OPTIONS_DEFAULT=GTK2
MUTAGEN_DESC=	Allow metadata manipulation
OGG2MP3_DESC=	Ogg Vorbis conversion to MP3 support
OPTIONS_EXCLUDE=NLS

ALL_TARGET=	messages
MAKE_ENV=	GPODDER_MANPATH_NO_SHARE="yes"
MAKEFILE=	makefile
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	-2.7
WANT_GNOME=	yes
INSTALLS_EGGINFO=yes
INSTALLS_ICONS=	yes
PORTDOCS=	PKG-INFO README

MAN1=		gpo.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
MAKE_ENV+=	GPODDER_INSTALL_UIS="cli gtk"
MAN1+=		${PORTNAME}.1
PLIST_SUB+=	GTK=""
RUN_DEPENDS+=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		xdg-open:${PORTSDIR}/devel/xdg-utils
USE_GNOME=	pygtk2
.else
MAKE_ENV+=	GPODDER_INSTALL_UIS="cli"
PLIST_SUB+=	GTK="@comment "
.endif
.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}notify>=0:${PORTSDIR}/devel/py-notify
.endif
.if ${PORT_OPTIONS:MMUTAGEN}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen
.endif
.if ${PORT_OPTIONS:MOGG2MP3}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
		oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
