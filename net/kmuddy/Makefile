## New ports collection makefile for:	kmuddy
# Date created:		2007-02-25
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	kmuddy
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	net games
MASTER_SITES=	http://www.kmuddy.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MUD client for KDE

LIB_DEPENDS=	mxp:${PORTSDIR}/net/libmxp
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_LDCONFIG=	yes

MAN1=		kmuddy.1

OPTIONS=	SDL "Use SDL for sound output (required for MIDI)" off

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
CONFIGURE_ARGS+=--with-sdl
USE_SDL=	mixer
.endif

post-patch:
	@${SETENV} LANG=C TZ=UTC ${TOUCH} -t 200511301031.32 ${WRKSRC}/admin/libtool.m4.in
	@${SETENV} LANG=C TZ=UTC ${TOUCH} -t 200510120853.48 ${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
