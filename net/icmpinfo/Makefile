# ex:ts=8
# Ports collection makefile for:  icmpinfo
# Date created:			  Mon June 23, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	icmpinfo
PORTVERSION=	1.11
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://hplyot.obspm.fr/net/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/admin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Looks at the icmp messages received by the host

ALL_TARGET=
MAN1=		icmpinfo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpinfo ${PREFIX}/bin
	${CHOWN} root ${PREFIX}/bin/icmpinfo
	${CHMOD} 4555 ${PREFIX}/bin/icmpinfo
	${INSTALL_MAN} ${WRKSRC}/icmpinfo.man ${PREFIX}/man/man1/${MAN1}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/icmpinfo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icmpinfo
.endif

.include <bsd.port.mk>
