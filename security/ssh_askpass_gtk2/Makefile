# New ports collection makefile for: ssh_askpass_gtk2
# Date created:        21 Aug 2003
# Whom:                mig
#
# $FreeBSD$
#

PORTNAME=	ssh_askpass_gtk2
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.cgabriel.org/download/ssh-askpass-fullscreen/
DISTNAME=	ssh-askpass-fullscreen-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A tiny GTK2 ssh askpass replacement

USE_GNOME=	gtk20

PLIST_FILES=	bin/ssh-askpass-fullscreen

do-install:
	cd ${WRKSRC};\
	${INSTALL_PROGRAM} ssh-askpass-fullscreen ${PREFIX}/bin/ssh-askpass-fullscreen;\

.include <bsd.port.mk>
