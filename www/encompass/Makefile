# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.1.0
CATEGORIES=	www gnome
MASTER_SITES=	http://www.geocities.com/lordzephyroth/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtkhtml.3:${PORTSDIR}/www/gtkhtml \
		glibwww.1:${PORTSDIR}/www/glibwww2 \
		gconf.8:${PORTSDIR}/devel/gconf
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes

MAKE_ENV=	MKDIR="${MKDIR}"

.include <bsd.port.mk>
