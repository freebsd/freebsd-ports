# ex:ts=8
# Ports collection makefile for:  icmpinfo
# Version required:     	  1.11
# Date created:			  Mon June 23, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.4 1997/08/04 20:47:58 obrien Exp $
#

DISTNAME=	icmpinfo-1.11
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://hplyot.obspm.fr/net/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/admin

MAINTAINER=     obrien@NUXI.com

ALL_TARGET=
MAN1=		icmpinfo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpinfo ${PREFIX}/bin
	/usr/sbin/chown root ${PREFIX}/bin/icmpinfo
	/bin/chmod 4555 ${PREFIX}/bin/icmpinfo
	${INSTALL_MAN} ${WRKSRC}/icmpinfo.man ${PREFIX}/man/man1/${MAN1}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/icmpinfo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icmpinfo
.endif


.include <bsd.port.mk>
