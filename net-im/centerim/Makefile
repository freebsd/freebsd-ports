# Created by: Frank Altpeter <frank@altpeter.de>
# $FreeBSD$

PORTNAME=	centerim
PORTVERSION=	4.22.10
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/releases/ \
		ftp://ftp.centerim.org/releases/

MAINTAINER=	frank@altpeter.de
COMMENT=	Text mode menu- and window-driven IM interface

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USES=		iconv
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-ssl --with-openssl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFLICTS=	centericq-[0-9]* centerim-devel-[0-9]*

OPTIONS_DEFINE=	NLS MULTIBYTE FRIBIDI MSN YAHOO AIM IRC JABBER GPGME RSS LJ GG
FRIBIDI_DESC=	Fribidi Support
MSN_DESC=	MSN Protocol
YAHOO_DESC=	Yahoo! Messenger Protocol
AIM_DESC=	AOL's Instant Messenger Protocol
IRC_DESC=	IRC Protocol
GPGME_DESC=	PGP encrypted Jabber messages
RSS_DESC=	RSS Support
LJ_DESC=	LiveJournal Support
GG_DESC=	Gadu-Gadu Protocol Support

MAN1=	cimconv.1 centerim.1

PORTDOCS=	FAQ README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MMULTIBYTE}
CONFIGURE_ARGS+=	--enable-locales-fix
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=		fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--with-fribidi
.endif

.if ! ${PORT_OPTIONS:MMSN}
CONFIGURE_ARGS+=	--disable-msn
.endif

.if ! ${PORT_OPTIONS:MYAHOO}
CONFIGURE_ARGS+=	--disable-yahoo
.endif

.if ! ${PORT_OPTIONS:MAIM}
CONFIGURE_ARGS+=	--disable-aim
.endif

.if ! ${PORT_OPTIONS:MIRC}
CONFIGURE_ARGS+=	--disable-irc
.endif

.if ! ${PORT_OPTIONS:MJABBER}
CONFIGURE_ARGS+=	--disable-jabber
.else
.endif

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=		gpgme.19:${PORTSDIR}/security/gpgme
#CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-gpgme
.endif

.if ! ${PORT_OPTIONS:MRSS}
CONFIGURE_ARGS+=	--disable-rss
.endif

.if ! ${PORT_OPTIONS:MLJ}
CONFIGURE_ARGS+=	--disable-lj
.endif

.if ! ${PORT_OPTIONS:MGG}
CONFIGURE_ARGS+=	--disable-gg
.else
LIB_DEPENDS+=		gadu.3:${PORTSDIR}/polish/ekg
LIBGADU=		-lgadu
.endif

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/python|/usr/bin/env python|' \
		${WRKSRC}/misc/CenterIMLog2HTML.py

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
