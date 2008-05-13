# New ports collection makefile for:	OpenSSH-askpass
# Date created:		27 February 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OpenSSH-askpass
PORTVERSION=	1.2.4.1
CATEGORIES=	security
MASTER_SITES=	http://www.jmknoble.net/software/x11-ssh-askpass/
DISTNAME=	x11-ssh-askpass-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Graphical password applet for entering SSH passphrase

USE_IMAKE=	yes
USE_XORG=	x11 xt

MAN1=		x11-ssh-askpass.1
MLINKS=		x11-ssh-askpass.1 ssh-askpass.1

DOCSDIR=	${PREFIX}/share/doc/ssh-askpass
PLIST_FILES=	bin/x11-ssh-askpass \
		bin/ssh-askpass \
		lib/X11/app-defaults/SshAskpass
PORTDOCS=	README TODO ChangeLog

pre-configure:
	cd ${WRKSRC} && ./configure --libexecdir=${PREFIX}/bin

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
