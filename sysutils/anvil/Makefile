# $FreeBSD$

PORTNAME=	anvil
PORTVERSION=	0.0.11
PORTREVISION=	1
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

OPTIONS_SINGLE=	SG1
OPTIONS_SINGLE_SG1=	 FETCH CURL WGET
OPTIONS_DEFAULT=	FETCH
FETCH_DESC=	Use fetch
CURL_DESC=	Use curl, not fetch
WGET_DESC=	Use wget, not fetch

CURL_RUN_DEPENDS=	curl:ftp/curl
WGET_RUN_DEPENDS=	wget:ftp/wget

FETCH_FETCH_TOOL=	fetch
CURL_FETCH_TOOL=	curl
WGET_FETCH_TOOL=	wget

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/anvil
	${INSTALL_DATA}   ${WRKDIR}/cert-shifter.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}   ${WRKDIR}/cert-puller.conf.sample  ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cert-shifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cert-puller  ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
