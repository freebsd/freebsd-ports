# Created by: Frank Altpeter <frank@altpeter.de>
# $FreeBSD$

PORTNAME=	centerim
PORTVERSION=	4.22.10
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/releases/ \
		ftp://ftp.centerim.org/releases/

MAINTAINER=	frank@altpeter.de
COMMENT=	Text mode menu- and window-driven IM interface

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		iconv gmake ncurses pkgconfig shebangfix
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-ssl --with-openssl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFLICTS=	centericq-[0-9]* centerim-devel-[0-9]*

SHEBANG_FILES=	misc/cimformathistory misc/cimextracthistory.pl
SHEBANG_LANG=	gawk
gawk_OLD_CMD=	/bin/gawk
gawk_CMD=	/usr/bin/awk

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

OPTIONS_DEFAULT=        MULTIBYTE FRIBIDI MSN YAHOO AIM IRC JABBER GPGME RSS LJ GG

OPTIONS_SUB=	yes

PORTDOCS=	FAQ README

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
MULTIBYTE_CONFIGURE_ENABLE=locales-fix
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_WITH=	fribidi
MSN_CONFIGURE_ENABLE=	msn
YAHOO_CONFIGURE_ENABLE=	yahoo
AIM_CONFIGURE_ENABLE=	aim
IRC_CONFIGURE_ENABLE=	irc
JABBER_CONFIGURE_ENABLE=jabber
RSS_CONFIGURE_ENABLE=	rss
LJ_CONFIGURE_ENABLE=	lj
GG_LIB_DEPENDS=		libgadu.so:polish/libgadu
GG_CONFIGURE_ENABLE=	gg
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_OFF=	--with-gpgme-prefix=/nonexistent

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/python|/usr/bin/env python|' \
		${WRKSRC}/misc/CenterIMLog2HTML.py
	@${REINPLACE_CMD} -e 's|-R$$found_dir|-Wl,-rpath,$$found_dir|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
