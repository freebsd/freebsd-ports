# New ports collection makefile for:	ehnt
# Date created:		2 August 2001
# Whom:			marck@rinet.ru
#
# $FreeBSD$
#

PORTNAME=	ehnt
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NO_ASN_DATA)
DISTFILES+=	${PORTNAME}_data-${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	marck@rinet.ru

USE_PERL5=	yes

MAN1=		ehnt.1
MAN8=		ehntserv.8

.if defined(NO_ASN_DATA)
post-extract:
	${TOUCH} ${WRKSRC}/asnc.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ehnt ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ehntserv ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/ehntserv.sh.sample ${PREFIX}/etc/rc.d/
	${INSTALL_MAN} ${WRKSRC}/ehnt.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ehntserv.8 ${PREFIX}/man/man8/
	${MKDIR} ${PREFIX}/share/ehnt
	${INSTALL_DATA} ${WRKSRC}/asnc.txt ${PREFIX}/share/ehnt/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ehnt
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ehnt/
.endif

.include <bsd.port.mk>
