# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.2.0
CATEGORIES=	www gnome
MASTER_SITES=	http://www.geocities.com/lordzephyroth/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtkhtml.4:${PORTSDIR}/www/gtkhtml \
		glibwww.1:${PORTSDIR}/www/glibwww \
		gconf-1.1:${PORTSDIR}/devel/gconf
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes

MAKE_ENV=	MKDIR="${MKDIR}"

.include <bsd.port.mk>
