# New ports collection makefile for:	ddup
# Version required:	2.0.4
# Date created:		30 September 1999
# Whom:			cjm2
#
# $FreeBSD$
#

DISTNAME=	ddup-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://gandy.dyndns.org/pub/ddup/ \
		http://www.phix.com/~java/

MAINTAINER=	cjm2@altavista.net

WRKSRC=		${WRKDIR}/ddup-nic

MAN1=		ddup.1
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddup ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/testip ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ddup.1.gz ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/ddup.conf ${PREFIX}/etc/ddup.conf.default
	${MKDIR} ${PREFIX}/share/doc/ddup
	${INSTALL_MAN} ${WRKSRC}/INSTALL-C ${PREFIX}/share/doc/ddup
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/ddup
	strip ${PREFIX}/sbin/ddup

.include <bsd.port.mk>
