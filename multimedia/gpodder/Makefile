# New ports collection makefile for:	gpodder
# Date created:				20 October 2007
# Whom:					Chess Griffin <chess@chessgriffin.com>
#
# $FreeBSD$
#

PORTNAME=	gpodder
PORTVERSION=	3.1.1
PORTREVISION=	1
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

OPTIONS=	GTK "With GTK UI" on \
		NOTIFY "Display notification bubbles for different events" off \
		MUTAGEN "Allow metadata manipulation" off \
		OGG2MP3 "Ogg Vorbis conversion to MP3 support" off \

ALL_TARGET=	messages
MAKE_ENV=	GPODDER_INSTALL_UIS="cli"
MAKEFILE=	makefile
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	-2.7
WANT_GNOME=	yes
INSTALLS_EGGINFO=yes
INSTALLS_ICONS=	yes

MAN1=		gpo.1 ${PORTNAME}.1

.include <bsd.port.options.mk>

.if defined(WITH_GTK)
MAKE_ENV=	GPODDER_INSTALL_UIS="cli gtk"
PLIST_SUB+=	GTK=""
RUN_DEPENDS+=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		xdg-open:${PORTSDIR}/devel/xdg-utils
USE_GNOME=	pygtk2
.else
PLIST_SUB+=	GTK="@comment "
.endif
.if defined(WITH_NOTIFY)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}notify>=0:${PORTSDIR}/devel/py-notify
.endif
.if defined(WITH_MUTAGEN)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen
.endif
.if defined(WITH_OGG2MP3)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
		oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

post-install:
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/${man} ${MANPREFIX}/man/man1/${man}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in PKG-INFO README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
