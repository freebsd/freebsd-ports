# New ports collection makefile for: dvd+rw-tools
# Date created:        2003-6-15
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	5.8.4.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	chuck@pkix.net
COMMENT=	DVD+RW burning software

RUN_DEPENDS=	${LOCALBASE}/bin/mkisofs:${PORTSDIR}/sysutils/mkisofs

MAN1=		growisofs.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
