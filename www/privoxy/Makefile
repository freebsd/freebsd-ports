# Created by: John von Essen
# $FreeBSD$

PORTNAME=	privoxy
PORTVERSION=	3.0.28
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${PORTVERSION}%20(stable)/ \
		SF/ijbswa/Sources/${PORTVERSION}%20%28stable%29
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Web proxy with advanced filtering capabilities

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		autoreconf cpe gmake shebangfix

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/privoxy-log-parser.pl tools/privoxy-regression-test.pl tools/uagen.pl

USE_RC_SUBR=	privoxy
SUB_FILES=	pkg-message

MAKEFILE=	GNUmakefile

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	privoxy-devel-[0-9]*

USERS=		privoxy
GROUPS=		privoxy

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ACCEPT_FILTER BROKEN_STRPTIME COMPRESSION \
		DEBUG DOCS EDITOR FORCE PRIVOXY_TOOLS TOGGLE

ACCEPT_FILTER_DESC=	Support for accf_http(9)
BROKEN_STRPTIME_DESC=	Enable workaround for standards/173421
COMPRESSION_DESC=	Support compression of buffered content
DOCS_DESC=		Let Privoxy serve the user manual
EDITOR_DESC=		Support use of the web-based action editor
FORCE_DESC=		Support bypassing of blocks
PRIVOXY_TOOLS_DESC=	Install Privoxy-Log-Parser, uagen, etc.
TOGGLE_DESC=		Support for remote toggling

OPTIONS_DEFAULT=	EDITOR FORCE TOGGLE PRIVOXY_TOOLS

OPTIONS_SUB=	yes

ACCEPT_FILTER_CONFIGURE_ON=	--enable-accept-filter

BROKEN_STRPTIME_CONFIGURE_ON=	--enable-strptime-sanity-checks

COMPRESSION_CONFIGURE_ON=	--enable-compression

DEBUG_CONFIGURE_ON=	--with-debug

EDITOR_CONFIGURE_OFF=	--disable-editor

FORCE_CONFIGURE_OFF=	--disable-force

TOGGLE_CONFIGURE_OFF=	--disable-toggle

PRIVOXY_TOOLS_USES=	perl5
PRIVOXY_TOOLS_USE=	PERL5=run
PRIVOXY_TOOLS_RUN_DEPENDS=	curl:ftp/curl

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile user\),#\1,' \
		-e 's,^\(filterfile user\),#\1,' \
		${WRKSRC}/config
	${REINPLACE_CMD} \
		-e 's,\(/etc/privoxy\),${PREFIX}\1,' ${WRKSRC}/tools/uagen.pl

post-patch-DOCS-on:
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) http://www.privoxy.org/user-manual/,\1 ${DOCSDIR}/user-manual,' \
		${WRKSRC}/config

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/privoxy/templates
	${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${STAGEDIR}${PREFIX}/etc/privoxy/templates
.for privoxy_tool in privoxy-log-parser.pl privoxy-regression-test.pl uagen.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/${privoxy_tool} ${STAGEDIR}${PREFIX}/bin
.endfor
.for defaultfile in default.action default.filter regression-tests.action
	${INSTALL_DATA} ${WRKSRC}/${defaultfile} ${STAGEDIR}${PREFIX}/etc/privoxy
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for examplefile in config match-all.action trust user.action
	${INSTALL_DATA} ${WRKSRC}/${examplefile} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
	${INSTALL_MAN}  ${WRKSRC}/privoxy.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/user-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${STAGEDIR}${DOCSDIR}/user-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css ${STAGEDIR}${DOCSDIR}/user-manual

.include <bsd.port.mk>
