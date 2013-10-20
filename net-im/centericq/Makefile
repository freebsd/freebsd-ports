# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	centericq
PORTVERSION=	4.21.0
PORTREVISION=	16
CATEGORIES=	net-im
MASTER_SITES=	http://thekonst.net/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode menu- and window-driven IM interface

USE_BZIP2=	yes
USES=		iconv
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++
CONFIGURE_ARGS=	--with-openssl --disable-konst

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

OPTIONS_DEFAULT=	GPGME

MAN1=	cicqconv.1 cicqsync.1

PORTDOCS=	FAQ README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
# Don't use optimization since it sefgaults in some cases otherwise.
CFLAGS:=	${CFLAGS:C/-O[0123456789]*/-O0/}
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MMULTIBYTE}
CONFIGURE_ARGS+=	--enable-locales-fix
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--with-fribidi
.endif

.if ${PORT_OPTIONS:MMSN}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
.else
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
.endif

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=		libgpgme.so:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-gpgme
.endif

.if ! ${PORT_OPTIONS:MRSS}
CONFIGURE_ARGS+=	--disable-rss
.endif

.if ! ${PORT_OPTIONS:MLJ}
CONFIGURE_ARGS+=	--disable-lj
.endif

.if ${PORT_OPTIONS:MGG}
LIB_DEPENDS+=	gadu.3:${PORTSDIR}/polish/ekg
LIBGADU=	-lgadu
.else
CONFIGURE_ARGS+=	--disable-gg
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
.for file in kkconsui-0.1/include/conf.h kkstrtext-0.1/conf.h kksystr-0.1/include/conf.h
	@(cd ${WRKSRC} ; \
	  ${MV} -f ${file} ${file}.orig ; \
	  ${GREP} -v "_G_config.h" ${file}.orig > ${file})
.endfor
	@${FIND} ${WRKSRC} -name "Makefile*" -type f -print0 | \
		${XARGS} -0 \
	        ${REINPLACE_CMD} -E \
		-e "s|-I\$$\(top_srcdir\)/libgadu-0.1|-I${LOCALBASE}/include|" \
		-e "s|-L\$$\(top_srcdir\)/libgadu-0.1|-L${LOCALBASE}/lib|" \
		-e 's|libgadu-0.1/*||' \
		-e 's|libgadu-0.1||' \
		-e 's|-llibgadu|${LIBGADU}|'

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
