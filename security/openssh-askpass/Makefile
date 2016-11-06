# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OpenSSH-askpass
PORTVERSION=	1.2.4.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.jmknoble.net/software/x11-ssh-askpass/
DISTNAME=	x11-ssh-askpass-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Graphical password applet for entering SSH passphrase

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README

USES=		uidfix
USE_XORG=	x11 xt sm ice
DOCSDIR=	${PREFIX}/share/doc/ssh-askpass
PLIST_FILES=	bin/x11-ssh-askpass \
		bin/ssh-askpass \
		lib/X11/app-defaults/SshAskpass \
		man/man1/ssh-askpass.1.gz \
		man/man1/x11-ssh-askpass.1.gz
PORTDOCS=	README TODO ChangeLog

OPTIONS_DEFINE=	DOCS

post-extract:
	${INSTALL_DATA} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
