# ex:ts=8
# Ports collection makefile for:  icb
# Version required:     	  5.0.9
# Date created:			  Tue Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.ucdavis.edu)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	icb-5.0.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.swcp.com/pub/icb/clients/unix/  \
		ftp://ftp.swcp.com/pub/icb/clients/  \
		ftp://ftp.swcp.com/pub/icb/server/  \
		ftp://ftp.empire.net/pub/icb/clients/  \
		ftp://ftp.cs.unm.edu/pub/armijo/icb.src/clients/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

do-configure:
	@cd ${WRKSRC}; \
	${SED} -e s,@PREFIX@,${PREFIX},g ${FILESDIR}/config >${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${PREFIX}/share/icb
	${INSTALL_DATA} ${WRKSRC}/icbserverdb ${PREFIX}/share/icb
	${INSTALL_DATA} ${WRKSRC}/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/share/icb

.include <bsd.port.mk>
