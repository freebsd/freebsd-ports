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

BROKEN=		does not fetch

RESTRICTED=	Redistribution prohibited by the license

IA32_BINARY_PORT=yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/nat %%DATADIR%%/passlist.txt %%DATADIR%%/userlist.txt man/man1/nat.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nat.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/passlist.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/userlist.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
