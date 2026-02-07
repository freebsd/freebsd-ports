PORTNAME=	privoxy
DISTVERSION=	4.1.0
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${DISTVERSION}%20(stable)/ \
		SF/ijbswa/Sources/${DISTVERSION}%20%28stable%29
DISTNAME=	${PORTNAME}-${DISTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Web proxy with advanced filtering capabilities
WWW=		https://www.privoxy.org/

LICENSE=		GPLv2+ GPLv3+
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE.GPLv3

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		autoreconf cpe gmake localbase shebangfix ssl
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	tools/privoxy-log-parser.pl tools/privoxy-regression-test.pl \
		tools/uagen.pl tools/url-pattern-translator.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extended-statistics --enable-pcre-host-patterns

MAKEFILE=	GNUmakefile

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	${PORTNAME}-devel

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-stable

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=	ACCEPT_FILTER BROKEN_STRPTIME BROTLI COMPRESSION DEBUG \
		DOCS EDITOR EXTERNAL_FILTERS FORCE HTTPS_INSPECTION \
		PRIVOXY_TOOLS TOGGLE ZSTD

OPTIONS_DEFAULT=	ACCEPT_FILTER BROTLI COMPRESSION EDITOR FORCE \
			HTTPS_INSPECTION PRIVOXY_TOOLS TOGGLE ZSTD
OPTIONS_SUB=	yes

ACCEPT_FILTER_DESC=	Support for accf_http(9)
BROKEN_STRPTIME_DESC=	Enable workaround for standards/173421
BROTLI_DESC=		Support decompression of Brotli-encoded content
COMPRESSION_DESC=	Support compression of buffered content
DOCS_DESC=		Let Privoxy serve the user manual
EDITOR_DESC=		Support use of the web-based action editor
EXTERNAL_FILTERS_DESC=	Support for external filters
FORCE_DESC=		Support bypassing of blocks
HTTPS_INSPECTION_DESC=	Support filtering of encrypted content
PRIVOXY_TOOLS_DESC=	Install Privoxy-Log-Parser, uagen, etc.
TOGGLE_DESC=		Support for remote toggling
ZSTD_DESC=		Support decompression of ZStandard-encoded content

ACCEPT_FILTER_CONFIGURE_ENABLE=	accept-filter

BROKEN_STRPTIME_CONFIGURE_ENABLE=	strptime-sanity-checks

BROTLI_LIB_DEPENDS=		libbrotlidec.so:archivers/brotli
BROTLI_CONFIGURE_WITH=		brotli

COMPRESSION_CONFIGURE_ENABLE=	compression

DEBUG_CONFIGURE_WITH=		debug

EDITOR_CONFIGURE_ENABLE=	editor

EXTERNAL_FILTERS_CONFIGURE_ENABLE=	external-filters

FORCE_CONFIGURE_ENABLE=		force

HTTPS_INSPECTION_CONFIGURE_WITH=	openssl

PRIVOXY_TOOLS_RUN_DEPENDS=	curl:ftp/curl
PRIVOXY_TOOLS_USES=		perl5
PRIVOXY_TOOLS_USE=		PERL5=run
PRIVOXY_TOOLS_VARS=		LICENSE+=ISCL LICENSE_COMB=multi

TOGGLE_CONFIGURE_ENABLE=	toggle

ZSTD_LIB_DEPENDS=		libzstd.so:archivers/zstd
ZSTD_CONFIGURE_WITH=		zstd

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${ETCDIR},' \
		-e 's,^\(logdir\) \.,\1 /var/log/${PORTNAME},' \
		-e 's,^\(actionsfile user\),#\1,' \
		-e 's,^\(filterfile user\),#\1,' \
		-e 's,^#\(listen-backlog -1\),\1,' \
		${WRKSRC}/config

post-patch-DOCS-on:
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) https://www.privoxy.org/user-manual/,\1 ${DOCSDIR}/user-manual,' \
		${WRKSRC}/config

post-patch-PRIVOXY_TOOLS-on:
	${REINPLACE_CMD} \
		-e 's,/etc/privoxy,${ETCDIR},' ${WRKSRC}/tools/uagen.pl

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/templates \
		 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${STAGEDIR}${ETCDIR}/templates
	${INSTALL_DATA} ${default.action default.filter \
		regression-tests.action:L:S|^|${WRKSRC}/|} \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${config match-all.action trust user.action:L:S|^|${WRKSRC}/|} \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/user-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css \
		${WRKSRC}/doc/webserver/user-manual/[a-z]* ${STAGEDIR}${DOCSDIR}/user-manual

do-install-PRIVOXY_TOOLS-on:
	${INSTALL_SCRIPT} ${privoxy-log-parser.pl privoxy-regression-test.pl \
		uagen.pl url-pattern-translator.pl:L:S|^|${WRKSRC}/tools/|} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
