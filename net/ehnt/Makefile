# New ports collection makefile for:	ehnt
# Date created:		2 August 2001
# Whom:			marck@rinet.ru
#
# $FreeBSD$
#

PORTNAME=	ehnt
PORTVERSION=	0.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	marck@rinet.ru

MAN1=		ehnt.1
MAN8=		ehntserv.8

do-install:
	${MKDIR} ${PREFIX}/share/ehnt
	${MKDIR} ${PREFIX}/share/doc/ehnt
	${INSTALL_PROGRAM} ${WRKSRC}/ehnt ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ehntserv ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/ehntserv.sh.sample ${PREFIX}/etc/rc.d/
	${INSTALL_DATA} ${WRKSRC}/asnc.txt ${PREFIX}/share/ehnt/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ehnt/
	${INSTALL_MAN} ${FILESDIR}/ehnt.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${FILESDIR}/ehntserv.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
