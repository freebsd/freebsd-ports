# $FreeBSD$

PORTNAME=	acme.sh
PORTVERSION=	2.8.3
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	ACME protocol client written in shell

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	Neilpang

USERS=	acme
GROUPS=	acme

OPTIONS_DEFINE=	DOCS BINDTOOLS IDN STANDALONE
OPTIONS_SINGLE=	HTTP
OPTIONS_SINGLE_HTTP=	CURL WGET
OPTIONS_DEFAULT=	CURL STANDALONE
BINDTOOLS_DESC=	Depend on bind-tools for nsupdate
BINDTOOLS_RUN_DEPENDS=	nsupdate:dns/bind-tools
IDN_RUN_DEPENDS=	idn2:dns/libidn2
STANDALONE_DESC=	Standalone mode requires SOCAT
STANDALONE_RUN_DEPENDS=	socat>0:net/socat

CURL_DESC=	Depend on cURL for HTTP(S) queries
WGET_DESC=	Depend on Wget for HTTP(S) queries

NO_ARCH=	yes
NO_BUILD=	yes

CURL_RUN_DEPENDS=	curl:ftp/curl
WGET_RUN_DEPENDS=	wget:ftp/wget

PORTDOCS=	README.md

SUB_FILES=	pkg-message

post-patch-IDN-on:
	${REINPLACE_CMD} -e 's|^ *idn |      idn2 |'\
		-e 's|_exists idn|_exists idn2|' ${WRKSRC}/acme.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/deploy ${STAGEDIR}${EXAMPLESDIR}/dnsapi
	${MKDIR} ${STAGEDIR}/var/db/acme/.acme.sh ${STAGEDIR}/var/db/acme/certs
	( cd ${WRKSRC} && ${COPYTREE_BIN} deploy ${STAGEDIR}${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} dnsapi ${STAGEDIR}${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} notify ${STAGEDIR}${EXAMPLESDIR} )
	${INSTALL_DATA} ${FILESDIR}/acme.sh.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/account.conf.sample ${STAGEDIR}/var/db/acme/.acme.sh
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/deploy ${STAGEDIR}/var/db/acme/.acme.sh
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/dnsapi ${STAGEDIR}/var/db/acme/.acme.sh
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/notify ${STAGEDIR}/var/db/acme/.acme.sh

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
