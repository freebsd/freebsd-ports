# Created by: mph
# $FreeBSD$

PORTNAME=	climm
PORTVERSION=	0.7.1
PORTREVISION=	12
CATEGORIES=	net-im
MASTER_SITES=	http://www.climm.org/source/ \
		http://http.bg.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI-based Multi-Messenger

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ICONV P2P TCL OTR REMOTE XMPP DOCS
OPTIONS_DEFAULT=ICONV P2P TCL OTR REMOTE
P2P_DESC=	Enable Peer2peer connection support
OTR_DESC=	Enable OTR encryption support
REMOTE_DESC=	Enable Remote control fifo support
XMPP_DESC=	Enable XMPP Jabber support

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct dh_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct dh_st'
.endif

.if ${PORT_OPTIONS:MOTR}
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-otr
LIB_DEPENDS+=		libotr.so.2:security/libotr3
.else
CONFIGURE_ARGS+=	--disable-otr
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=			iconv
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${PORT_OPTIONS:MP2P}
CONFIGURE_ARGS+=	--enable-peer2peer
.else
CONFIGURE_ARGS+=	--disable-peer2peer
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if ${PORT_OPTIONS:MREMOTE}
CONFIGURE_ARGS+=	--enable-remote
.else
CONFIGURE_ARGS+=	--disable-remote
.endif

.if ${PORT_OPTIONS:MXMPP}
CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-xmpp --enable-ssl=gnutls \
			--with-libgcrypt-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkgconf gnutls"
LIB_DEPENDS+=		libiksemel.so:textproc/iksemel \
			libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
.else
USES+=			ssl
CONFIGURE_ARGS+=	--disable-xmpp --enable-ssl=openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^noinst_LIBRARIES/d' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/ac_lib/s/tcl8\./tcl8/g' \
		-e '/libgnutls_config_version=/s/--version/--modversion/' \
		${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/climm.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/climmrc.5 ${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/climmcmds.7 ${STAGEDIR}${PREFIX}/man/man7
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ext in i18n logformat png txt xpm
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
