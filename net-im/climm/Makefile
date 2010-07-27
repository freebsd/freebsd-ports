# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	climm
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.climm.org/source/ \
		http://http.bg.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	CLI-based Multi-Messenger

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		climm.1
MAN5=		climmrc.5
MAN7=		climmcmds.7

OPTIONS=	LIBICONV "Iconv character set conversion" on \
		P2P "Peer2peer connection support" on \
		TCL "TCL scripting support" on \
		OTR "OTR encryption support" on \
		REMOTE "Remote control fifo support" on \
		XMPP "XMPP Jabber support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OTR)
CONFIGURE_ARGS+=	--disable-otr
.else
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-otr
LIB_DEPENDS+=		otr:${PORTSDIR}/security/libotr
.endif

.if defined(WITHOUT_LIBICONV)
CONFIGURE_ARGS+=	--disable-iconv
.else
USE_ICONV=		yes
.endif

.if defined(WITHOUT_P2P)
CONFIGURE_ARGS+=	--disable-peer2peer
.endif

.if defined(WITHOUT_TCL)
CONFIGURE_ARGS+=	--disable-tcl
.else
USE_TCL=		yes
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.endif

.if defined(WITHOUT_REMOTE)
CONFIGURE_ARGS+=	--disable-remote
.endif

.if defined(WITHOUT_XMPP)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--disable-xmpp --enable-ssl=openssl
.else
CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-xmpp --enable-ssl=gnutls \
			--with-libgcrypt-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config gnutls"
BUILD_DEPENDS+=		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=		iksemel:${PORTSDIR}/textproc/iksemel \
			gnutls:${PORTSDIR}/security/gnutls \
			gcrypt:${PORTSDIR}/security/libgcrypt \
			gpg-error:${PORTSDIR}/security/libgpg-error
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc//' ${WRKSRC}/Makefile.in
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

.include <bsd.port.post.mk>
