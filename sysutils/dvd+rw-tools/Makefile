# New ports collection makefile for: dvd+rw-tools
# Date created:        2003-6-15
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	5.10.4.5.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	chuck@pkix.net
COMMENT=	DVD burning software

RUN_DEPENDS=	${LOCALBASE}/bin/mkisofs:${PORTSDIR}/sysutils/mkisofs

MAN1=		growisofs.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
