# New ports collection makefile for:	OpenSSH-askpass
# Date created:		27 February 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OpenSSH-askpass
PORTVERSION=	1.2.2.2001.02.24
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical password applet for entering SSH passphrase

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/X11/xc/programs/ssh-askpass
USE_IMAKE=	yes

MAN1=		ssh-askpass.1
MANCOMPRESSED=	yes

DOCSDIR=	${PREFIX}/share/doc/ssh-askpass
PLIST_FILES=	bin/ssh-askpass lib/X11/app-defaults/SshAskpass
PORTDOCS=	README

makesrctarball: fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${DISTNAME}.tar.gz\"."; \
	${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
