# $FreeBSD$

PORTNAME=	anvil
PORTVERSION=	0.0.10
CATEGORIES=	sysutils

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Tools for distributing ssl certificates

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	dlangille

USERS=	anvil
GROUPS=	anvil

SUB_FILES+=	cert-shifter.conf.sample cert-puller.conf.sample pkg-install pkg-message

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/anvil
	${INSTALL_DATA}   ${WRKDIR}/cert-shifter.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}   ${WRKDIR}/cert-puller.conf.sample  ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cert-shifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cert-puller  ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
