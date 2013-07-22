# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OpenSSH-askpass
PORTVERSION=	1.2.4.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.jmknoble.net/software/x11-ssh-askpass/
DISTNAME=	x11-ssh-askpass-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Graphical password applet for entering SSH passphrase

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README

USE_XORG=	x11 xt sm ice
DOCSDIR=	${PREFIX}/share/doc/ssh-askpass
PLIST_FILES=	bin/x11-ssh-askpass \
		bin/ssh-askpass \
		lib/X11/app-defaults/SshAskpass
PORTDOCS=	README TODO ChangeLog
MAKE_JOBS_SAFE=	yes

MAN1=		x11-ssh-askpass.1
MLINKS=		x11-ssh-askpass.1 ssh-askpass.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	${INSTALL_DATA} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
