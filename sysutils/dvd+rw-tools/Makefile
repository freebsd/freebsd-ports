# New ports collection makefile for: dvd+rw-tools
# Date created:        2003-6-15
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	5.19.4.9.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	chuck@pkix.net
COMMENT=	DVD burning software

RUN_DEPENDS=	${LOCALBASE}/bin/mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_REINPLACE=	yes

MAN1=		growisofs.1

# This software is installed setuid-root (mode 4755) by default.
INSTALL_TARGET=		BIN_MODE=00755 install

post-patch:
	${REINPLACE_CMD} -e 's/-O2//' ${WRKSRC}/Makefile.m4

post-install:
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/index.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
