# Created by: John von Essen

PORTNAME=	privoxy
PORTVERSION=	3.0.33
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${PORTVERSION}%20(stable)/ \
		SF/ijbswa/Sources/${PORTVERSION}%20%28stable%29
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Web proxy with advanced filtering capabilities

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		autoreconf cpe gmake shebangfix ssl
USE_RC_SUBR=	privoxy

SHEBANG_FILES=	tools/privoxy-log-parser.pl tools/privoxy-regression-test.pl \
		tools/uagen.pl tools/url-pattern-translator.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extended-statistics --enable-pcre-host-patterns

MAKEFILE=	GNUmakefile

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	privoxy-devel

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

USERS=		privoxy
GROUPS=		privoxy

OPTIONS_DEFINE=	ACCEPT_FILTER BROKEN_STRPTIME BROTLI COMPRESSION DEBUG \
		DOCS EDITOR FORCE HTTPS_INSPECTION PRIVOXY_TOOLS TOGGLE

OPTIONS_DEFAULT=	ACCEPT_FILTER BROTLI DOCS EDITOR FORCE \
			HTTPS_INSPECTION TOGGLE PRIVOXY_TOOLS
OPTIONS_SUB=	yes

ACCEPT_FILTER_DESC=	Support for accf_http(9)
BROKEN_STRPTIME_DESC=	Enable workaround for standards/173421
BROTLI_DESC=		Support decompression of Brotli-encoded content
COMPRESSION_DESC=	Support compression of buffered content
DOCS_DESC=		Let Privoxy serve the user manual
EDITOR_DESC=		Support use of the web-based action editor
FORCE_DESC=		Support bypassing of blocks
HTTPS_INSPECTION_DESC=	Support filtering of encrypted content
PRIVOXY_TOOLS_DESC=	Install Privoxy-Log-Parser, uagen, etc.
TOGGLE_DESC=		Support for remote toggling

ACCEPT_FILTER_CONFIGURE_ON=	--enable-accept-filter

BROKEN_STRPTIME_CONFIGURE_ON=	--enable-strptime-sanity-checks

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_CONFIGURE_ON=	--with-brotli

COMPRESSION_CONFIGURE_ON=	--enable-compression

DEBUG_CONFIGURE_ON=	--with-debug

EDITOR_CONFIGURE_OFF=	--disable-editor

FORCE_CONFIGURE_OFF=	--disable-force

HTTPS_INSPECTION_CONFIGURE_ON=	--with-openssl

PRIVOXY_TOOLS_RUN_DEPENDS=	curl:ftp/curl
PRIVOXY_TOOLS_USES=	perl5
PRIVOXY_TOOLS_USE=	PERL5=run

TOGGLE_CONFIGURE_OFF=	--disable-toggle

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile user\),#\1,' \
		-e 's,^\(filterfile user\),#\1,' \
		-e 's,^#\(listen-backlog -1\),\1,' \
		${WRKSRC}/config
	${REINPLACE_CMD} \
		-e 's,\(/etc/privoxy\),${PREFIX}\1,' ${WRKSRC}/tools/uagen.pl

post-patch-DOCS-on:
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) https://www.privoxy.org/user-manual/,\1 ${DOCSDIR}/user-manual,' \
		${WRKSRC}/config

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/privoxy/templates
	${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${STAGEDIR}${PREFIX}/etc/privoxy/templates
.for privoxy_tool in privoxy-log-parser.pl privoxy-regression-test.pl uagen.pl url-pattern-translator.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/${privoxy_tool} ${STAGEDIR}${PREFIX}/bin
.endfor
.for defaultfile in default.action default.filter regression-tests.action
	${INSTALL_DATA} ${WRKSRC}/${defaultfile} ${STAGEDIR}${PREFIX}/etc/privoxy
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for examplefile in config match-all.action trust user.action
	${INSTALL_DATA} ${WRKSRC}/${examplefile} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
	${INSTALL_MAN}  ${WRKSRC}/privoxy.8 ${STAGEDIR}${MAN1PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/user-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${STAGEDIR}${DOCSDIR}/user-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css ${STAGEDIR}${DOCSDIR}/user-manual

.include <bsd.port.mk>
