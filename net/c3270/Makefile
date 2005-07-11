# New ports collection makefile for:	c3270
# Date created:		04 October 2004
# Whom:			pdseniura@techie.com
#
# $FreeBSD$
#

PORTNAME=	c3270
PORTVERSION=	3.3.4
CATEGORIES=	net
MASTER_SITES=	http://x3270.bgp.nu/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Full-screen curses-based remote login to IBM mainframes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/([0-9]\.[0-9])(\..*)/\1/}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_OPENSSL=	yes

USE_REINPLACE=	yes

MAN1=		c3270.1 \
		x3270if.1 \
		x3270-script.1 \
		pr3287.1
MAN5=		ibm_hosts.5
MANCOMPRESSED=	no

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

# c3270's ./configure script supports these.
# Within it all options except DBCS are enabled by default.

OPTIONS=OPENSSL		'Build with OpenSSL support'		on	\
	READLINE	'Use system Readline library'		on	\
	PR3287		'Build pr3287 component'		on	\
	ANSI		'Include NVT (ANSI) support'		on	\
	APL		'Include APL support'			on	\
	DBCS		'Include EBCDIC DBCS support'		off	\
	FT		'Include IND\$$FILE support'		on	\
	LOCAL_PROCESS	'Include Local Process support'		on	\
	PRINTER		'Include printer session support'	on	\
	SCRIPT		'Include scripting support'		on	\
	TN3270E		'Include TN3270-Extended support'	on	\
	TRACE		'Include trace support'			on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPENSSL) && !defined(WITH_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.undef USE_OPENSSL
.endif

.if defined(WITHOUT_READLINE) && !defined(WITH_READLINE)
CONFIGURE_ARGS+=	--without-readline
.endif

.if defined(WITHOUT_PR3287) && !defined(WITH_PR3287)
CONFIGURE_ARGS+=	--without-pr3287
.endif

.if defined(WITHOUT_ANSI) && !defined(WITH_ANSI)
CONFIGURE_ARGS+=	--disable-ansi
.endif

.if defined(WITHOUT_APL) && !defined(WITH_APL)
CONFIGURE_ARGS+=	--disable-apl
.endif

# EBCDIC double-byte character set support is disabled by default
.if defined(WITH_DBCS) && !defined(WITHOUT_DBCS)
CONFIGURE_ARGS+=	--enable-dbcs
BUILD_DEPENDS+=	${LOCALBASE}/include/unicode/ucnv.h:${PORTSDIR}/devel/icu2:install
PLIST_SUB+=	DBCS=""
.else
PLIST_SUB+=	DBCS="@comment "
.endif

.if defined(WITHOUT_FT) && !defined(WITH_FT)
CONFIGURE_ARGS+=	--disable-ft
.endif

.if defined(WITHOUT_LOCAL_PROCESS) && !defined(WITH_LOCAL_PROCESS)
CONFIGURE_ARGS+=	--disable-local-process
.endif

.if defined(WITHOUT_PRINTER) && !defined(WITH_PRINTER)
CONFIGURE_ARGS+=	--disable-printer
.endif

.if defined(WITHOUT_SCRIPT) && !defined(WITH_SCRIPT)
CONFIGURE_ARGS+=	--disable-script
.endif

.if defined(WITHOUT_TN3270E) && !defined(WITH_TN3270E)
CONFIGURE_ARGS+=	--disable-tn3270e
.endif

.if defined(WITHOUT_TRACE) && !defined(WITH_TRACE)
CONFIGURE_ARGS+=	--disable-trace
.endif

pre-patch:
# icu2-2.8 gets choked with subchar1 tags
.if defined(WITH_DBCS) && !defined(WITHOUT_DBCS)
	${REINPLACE_CMD} -e 's/^<subchar1>/#<subchar1>/g' \
		${WRKSRC}/*.ucm
.endif

post-install:
	@( cd ${WRKSRC} && ${GMAKE} ${MAKE_FLAGS} Makefile install.man )
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
.for i in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/html/${i} ${DOCSDIR}/${i}
.endfor
	@${ECHO_MSG} "===> Extra Documentation installed in ${DOCSDIR}/html ."
.endif

.include <bsd.port.post.mk>
