# Created by: Andrei Lavreniyuk <andy.lavr@gmail.com>
# $FreeBSD$

PORTNAME=	torsocks
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	GOOGLE_CODE \
		http://tor.reactor-xg.kiev.ua/files/

MAINTAINER=	andy.lavr@gmail.com
COMMENT=	Most SOCKS-friendly applications way with Tor

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool aclocal autoconf libtoolize
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		torsocks.1 usewithtor.1
MAN5=		torsocks.conf.5
MAN8=		torsocks.8

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	OLDMETHOD NODEBUG DOCS

OPTIONS_SINGLE=		DNS
OPTIONS_SINGLE_DNS=	DEFAULT SOCKSDNS HOSTNAMES

SOCKSDNS_DESC=	Use socks server for DNS lookups
OLDMETHOD_DESC=	Do not use RTLD_NEXT parameter to dlsym
NODEBUG_DESC=	Disable output of error messages
HOSTNAMES_DESC=	Enable DNS lookups of socks server
DOCS_DESC=	Install examples and docs
DEFAULT_DESC=	DNS lookups default

OPTIONS_DEFAULT=	DOCS DEFAULT

PORTDOCS=	INSTALL README TODO ChangeLog

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCKSDNS}
CONFIGURE_ARGS+=	--enable-socksdns

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the SOCKSDNS option."
	@${ECHO_MSG} "This option causes torsocks to intercept"
	@${ECHO_MSG} "DNS lookups and attempt to force them"
	@${ECHO_MSG} "to use TCP instead of UDP and thus"
	@${ECHO_MSG} "be proxied through the socks server."
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MOLDMETHOD}
CONFIGURE_ARGS+=	--enable-oldmethod

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the OLDMETHOD option."
	@${ECHO_MSG} "This forces torsocks not to use the"
	@${ECHO_MSG} "RTLD_NEXT parameter to dlsym to get the"
	@${ECHO_MSG} "address of the connect() method torsocks"
	@${ECHO_MSG} "overrides, instead it loads a reference"
	@${ECHO_MSG} "to the libc shared library and then uses dlsym()."
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MNODEBUG}
CONFIGURE_ARGS+=	--disable-debug

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the NODEBUG option."
	@${ECHO_MSG} "This configuration option tells torsocks"
	@${ECHO_MSG} "to never output error messages to stderr."
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MHOSTNAMES}
CONFIGURE_ARGS+=	--enable-hostnames

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the HOSTNAMES option."
	@${ECHO_MSG} "This enables DNS lookups on names"
	@${ECHO_MSG} "provided as socks servers in the config"
	@${ECHO_MSG} "file. This option is not allowed"
	@${ECHO_MSG} "if socks dns is enabled since torsocks"
	@${ECHO_MSG} "can't send a socks dns request to resolve"
	@${ECHO_MSG} "the location of the socks server."
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|' ${WRKSRC}/src/torsocks.in
	@${REINPLACE_CMD} -e 's|MAP_ANONYMOUS|MAP_ANON|' ${WRKSRC}/src/dead_pool.c
	@${MV} ${WRKSRC}/doc/torsocks.conf ${WRKSRC}/doc/torsocks.conf.sample
	@${MV} ${WRKSRC}/configure.in ${WRKSRC}/configure.ac
	@${MKDIR} ${WRKSRC}/m4

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/*.sample ${PREFIX}/etc
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
