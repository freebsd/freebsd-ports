# Ports collection makefile for:  nat
# Date created:			  May 24 2001
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	nat
PORTVERSION=	20
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.tux.org/pub/security/secnet/tools/nat20beta/ \
		ftp://ftp.cert.dfn.de/pub/tools/net-mgmt/nat/nat20beta/ \
		ftp://ftp.spin.ad.jp/pub/Security/nat/nat20beta/
DISTNAME=	${PORTNAME}${PORTVERSION}.freebsd

MAINTAINER=	ports@oven.org
COMMENT=	NetBIOS auditing tool

NO_PACKAGE=	"Redistribution prohibited by the license"

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
MAN1=		nat.1

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/nat ${LOCALBASE}/bin
		${INSTALL_MAN} ${WRKSRC}/nat.1 ${LOCALBASE}/man/man1
		${MKDIR} ${LOCALBASE}/share/nat
		${INSTALL_DATA} ${WRKSRC}/passlist.txt ${LOCALBASE}/share/nat
		${INSTALL_DATA} ${WRKSRC}/userlist.txt ${LOCALBASE}/share/nat

.include <bsd.port.mk>
