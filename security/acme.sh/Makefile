PORTNAME=	acme.sh
PORTVERSION=	3.1.1
PORTREVISION=	1	
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	ACME protocol client written in shell
WWW=		https://github.com/Neilpang/acme.sh/

LICENSE=	GPLv3+

USES=		shebangfix
SHEBANG_FILES=	deploy/synology_dsm.sh

USE_GITHUB=	yes
GH_ACCOUNT=	acmesh-official

USERS=		acme
GROUPS=		acme

OPTIONS_DEFINE=		BINDTOOLS DOCS EXAMPLES IDN STANDALONE
OPTIONS_DEFAULT=	CURL STANDALONE
OPTIONS_SINGLE=		HTTP
OPTIONS_SINGLE_HTTP=	CURL WGET

BINDTOOLS_DESC=	Depend on bind-tools for nsupdate

CURL_DESC=		Depend on cURL for HTTP(S) queries
STANDALONE_DESC=	Standalone mode requires SOCAT
WGET_DESC=		Depend on Wget for HTTP(S) queries

NO_ARCH=	yes
NO_BUILD=	yes

BINDTOOLS_RUN_DEPENDS=	nsupdate:dns/bind-tools
CURL_RUN_DEPENDS=	curl:ftp/curl
IDN_RUN_DEPENDS=	idn2:dns/libidn2
STANDALONE_RUN_DEPENDS=	socat>0:net/socat
WGET_RUN_DEPENDS=	wget:ftp/wget

PORTDOCS=	README.md

SUB_FILES=	acme-crontab pkg-message

SUB_LIST=	ACME_USER=acme

post-patch-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|sed -i "|sed -i bak "|' ${WRKSRC}/dnsapi/dns_nsd.sh

post-patch-IDN-on:
	${REINPLACE_CMD} -e 's|^ *idn |      idn2 |'\
		-e 's|_exists idn|_exists idn2|' ${WRKSRC}/acme.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

	${MKDIR} ${STAGEDIR}/var/db/acme/.acme.sh \
	         ${STAGEDIR}/var/db/acme/certs \
	         ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
	         ${STAGEDIR}${EXAMPLESDIR}

	${INSTALL_DATA} ${FILESDIR}/account.conf.sample ${STAGEDIR}/var/db/acme/.acme.sh

	${INSTALL_DATA} ${WRKDIR}/acme-crontab     ${STAGEDIR}${EXAMPLESDIR}/acme.sh-cron.d

	${INSTALL_DATA} ${FILESDIR}/acme-newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/acme.sh.conf.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/deploy ${STAGEDIR}${EXAMPLESDIR}/dnsapi

	( cd ${WRKSRC} && ${COPYTREE_BIN} deploy ${STAGEDIR}${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} dnsapi ${STAGEDIR}${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} notify ${STAGEDIR}${EXAMPLESDIR} )
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/deploy ${STAGEDIR}/var/db/acme/.acme.sh
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/dnsapi ${STAGEDIR}/var/db/acme/.acme.sh
	${RLN} ${STAGEDIR}/${EXAMPLESDIR}/notify ${STAGEDIR}/var/db/acme/.acme.sh

.include <bsd.port.mk>
