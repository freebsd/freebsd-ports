# New ports collection makefile for: ssh_askpass_gtk2
# Date created:        21 Aug 2003
# Whom:                mig
#
# $FreeBSD$
#

PORTNAME=		ssh_askpass_gtk2
PORTVERSION=		0.3
PORTREVISION=	4
CATEGORIES=		security
MASTER_SITES=		http://www.cgabriel.org/sw/gtk2-ssh-askpass/
DISTNAME=		gtk2-ssh-askpass-0.3

MAINTAINER=		mig@mig-29.net
COMMENT=		A tiny GTK2 ssh askpass replacement

USE_X_PREFIX=		yes
USE_GNOME=		gtk20

MAN1=			ssh-askpass-gtk2.1
PLIST_FILES=		bin/ssh-askpass-gtk2

do-install:
	cd ${WRKSRC};\
	${INSTALL_PROGRAM} gtk2-ssh-askpass ${PREFIX}/bin/ssh-askpass-gtk2;\
	${INSTALL_MAN} debian/gtk2-ssh-askpass.1 ${PREFIX}/man/man1/ssh-askpass-gtk2.1

.include <bsd.port.mk>
