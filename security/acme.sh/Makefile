# $FreeBSD$

PORTNAME=	acme.sh
PORTVERSION=	2.7.5
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	ACME protocol client written in shell

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	Neilpang

USERS=	acme
GROUPS=	acme

OPTIONS_DEFINE=	DOCS BINDTOOLS STANDALONE
OPTIONS_SINGLE=	HTTP
OPTIONS_SINGLE_HTTP=	CURL WGET
OPTIONS_DEFAULT=	CURL
BINDTOOLS_DESC=	Depend on bind-tools for nsupdate
BINDTOOLS_RUN_DEPENDS=	${LOCALBASE}/bin/nsupdate:dns/bind-tools
STANDALONE_DESC=	Standalone mode requres SOCAT
STANDALONE_RUN_DEPENDS=	socat>0:net/socat

CURL_DESC=	Depend on cURL for HTTP(S) queries
WGET_DESC=	Depend on Wget for HTTP(S) queries

NO_ARCH=	yes
NO_BUILD=	yes

CURL_RUN_DEPENDS=	curl:ftp/curl
WGET_RUN_DEPENDS=	wget:ftp/wget

PORTDOCS=	README.md

SUB_FILES=	pkg-install pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/deploy ${STAGEDIR}${EXAMPLESDIR}/dnsapi
	( cd ${WRKSRC} && ${COPYTREE_BIN} deploy ${STAGEDIR}${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} dnsapi ${STAGEDIR}${EXAMPLESDIR} )
	${INSTALL_DATA} ${FILESDIR}/acme.sh ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
