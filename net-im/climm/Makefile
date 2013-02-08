# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	climm
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://www.climm.org/source/ \
		http://http.bg.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	CLI-based Multi-Messenger

USE_GMAKE=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		climm.1
MAN5=		climmrc.5
MAN7=		climmcmds.7

OPTIONS_DEFINE=	ICONV P2P TCL OTR REMOTE XMPP
OPTIONS_DEFAULT=ICONV P2P TCL OTR REMOTE
P2P_DESC=	Enable Peer2peer connection support
OTR_DESC=	Enable OTR encryption support
REMOTE_DESC=	Enable Remote control fifo support
XMPP_DESC=	Enable XMPP Jabber support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOTR}
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-otr
LIB_DEPENDS+=		otr.4:${PORTSDIR}/security/libotr3
.else
CONFIGURE_ARGS+=	--disable-otr
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=		yes
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${PORT_OPTIONS:MP2P}
CONFIGURE_ARGS+=	--enable-peer2peer
.else
CONFIGURE_ARGS+=	--disable-peer2peer
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=		yes
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
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
USE_PKGCONFIG=		yes
LIB_DEPENDS+=		iksemel:${PORTSDIR}/textproc/iksemel \
			gnutls:${PORTSDIR}/security/gnutls \
			gcrypt:${PORTSDIR}/security/libgcrypt \
			gpg-error:${PORTSDIR}/security/libgpg-error
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--disable-xmpp --enable-ssl=openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^noinst_LIBRARIES/d' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/ac_lib/s/tcl8\./tcl8/g' \
		-e '/libgnutls_config_version=/s/--version/--modversion/' \
		${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/climm.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/climmrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/climmcmds.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for ext in i18n logformat png txt xpm
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
