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

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/X11/xc/programs/ssh-askpass
USE_IMAKE=	yes

MAN1=		ssh-askpass.1
MANCOMPRESSED=	yes

makesrctarball: fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${PKGNAME}.tar.gz\"."; \
	${TAR} cfz ${PKGNAME}.tar.gz ${PKGNAME}

pre-install:
	${MKDIR} ${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssh-askpass/

.include <bsd.port.mk>
