# ex:ts=8
# Ports collection makefile for:  icb
# Date created:			  Tue Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	icb
PORTVERSION=	5.1.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.obfuscation.org/ftp/pub/icb/  \
		ftp://ftp.obfuscation.org/pub/icb/
DISTNAME=	cicb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${PREFIX}/share/icb
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${PREFIX}/share/icb
	${INSTALL_DATA} ${WRKSRC}/contrib/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofunctions \
		${PREFIX}/share/icb

.include <bsd.port.mk>
