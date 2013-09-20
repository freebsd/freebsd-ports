# Created by: John von Essen
# $FreeBSD$

PORTNAME=	privoxy
PORTVERSION=	3.0.21
CATEGORIES=	www ipv6
MASTER_SITES=	SF/ijbswa/Sources/${PORTVERSION}%20%28stable%29
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

USES=		gmake
USE_AUTOTOOLS=	autoconf

USE_RC_SUBR=	privoxy
SUB_FILES=	pkg-message

MAKEFILE=	GNUmakefile

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	privoxy-devel-[0-9]*

MAN1=		privoxy.1

USERS=		privoxy
GROUPS=		privoxy

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ACCEPT_FILTER BROKEN_STRPTIME COMPRESSION DEBUG \
		DOCS EDITOR FORCE PRIVOXY_TOOLS TOGGLE

ACCEPT_FILTER_DESC=	Support for accf_http(9)
BROKEN_STRPTIME_DESC=	Enable workaround for standards/173421
COMPRESSION_DESC=	Support compression of buffered content
DOCS_DESC=		Let Privoxy serve the user manual
EDITOR_DESC=		Support use of the web-based action editor
FORCE_DESC=		Support bypassing of blocks
PRIVOXY_TOOLS_DESC=	Install Privoxy-Log-Parser, uagen, etc.
TOGGLE_DESC=		Support for remote toggling

OPTIONS_DEFAULT=	BROKEN_STRPTIME EDITOR DOCS FORCE TOGGLE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACCEPT_FILTER}
CONFIGURE_ARGS+=	 --enable-accept-filter
.endif

.if ${PORT_OPTIONS:MCOMPRESSION}
CONFIGURE_ARGS+=	 --enable-compression
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debug
.endif

.if ! ${PORT_OPTIONS:MEDITOR}
CONFIGURE_ARGS+=	--disable-editor
.endif

.if ! ${PORT_OPTIONS:MFORCE}
CONFIGURE_ARGS+=	--disable-force
.endif

.if ${PORT_OPTIONS:MBROKEN_STRPTIME}
CONFIGURE_ARGS+=	--enable-strptime-sanity-checks
.endif

.if ! ${PORT_OPTIONS:MTOGGLE}
CONFIGURE_ARGS+=	--disable-toggle
.endif

.if ${PORT_OPTIONS:MPRIVOXY_TOOLS}
USES+=		perl5
USE_PERL5=	run
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	PRIVOXY_TOOLS=""
.else
PLIST_SUB+=	PRIVOXY_TOOLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile user\),#\1,' \
		-e 's,^\(filterfile user\),#\1,' \
	${WRKSRC}/config
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) http://www.privoxy.org/user-manual/,\1 ${DOCSDIR}/user-manual,' \
	${WRKSRC}/config
.endif
	${REINPLACE_CMD} \
		-e 's,\(/etc/privoxy\),${PREFIX}\1,' ${WRKSRC}/tools/uagen.pl

pre-configure:
	@cd ${WRKSRC}; ${AUTOHEADER}

do-install:
	@${MKDIR} ${PREFIX}/etc/privoxy/templates
	@${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${PREFIX}/etc/privoxy/templates
.if ${PORT_OPTIONS:MPRIVOXY_TOOLS}
.for privoxy_tool in privoxy-log-parser.pl privoxy-regression-test.pl uagen.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/${privoxy_tool} ${PREFIX}/bin
.endfor
.endif
.for defaultfile in default.action default.filter regression-tests.action
	@${INSTALL_DATA} ${WRKSRC}/${defaultfile} ${PREFIX}/etc/privoxy
	@${CHOWN} privoxy:privoxy ${PREFIX}/etc/privoxy/${defaultfile}
	@${CHMOD} 0444 ${PREFIX}/etc/privoxy/${defaultfile}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for examplefile in config match-all.action trust user.action
	@${INSTALL_DATA} ${WRKSRC}/${examplefile} ${EXAMPLESDIR}/
	@${CHOWN} privoxy:privoxy ${EXAMPLESDIR}/${examplefile}
	@${CHMOD} 0640 ${EXAMPLESDIR}/${examplefile}
.endfor
	@${INSTALL_MAN}  ${WRKSRC}/privoxy.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/user-manual
	@${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${DOCSDIR}/user-manual
	@${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css ${DOCSDIR}/user-manual
.endif

post-install:
	@${MKDIR} /var/run/privoxy
	@${CHOWN} privoxy:privoxy /var/run/privoxy
	@${CHMOD} 0750 /var/run/privoxy
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
