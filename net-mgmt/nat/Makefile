# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	nat
PORTVERSION=	20
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.tux.org/pub/security/secnet/tools/nat20beta/ \
		http://apache.uasw.edu/pub/security/dfn-cert/tools/net/nat/
DISTNAME=	${PORTNAME}${PORTVERSION}.freebsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetBIOS auditing tool

LICENSE_FILE=	${WRKSRC}/LICENSE

RESTRICTED=	Redistribution prohibited by the license

IA32_BINARY_PORT=yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MAN1=		nat.1
PLIST_FILES=	bin/nat %%DATADIR%%/passlist.txt %%DATADIR%%/userlist.txt
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nat.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/passlist.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/userlist.txt ${DATADIR}

.include <bsd.port.mk>
