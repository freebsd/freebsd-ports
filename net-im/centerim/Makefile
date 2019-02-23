# Created by: Frank Altpeter <frank@altpeter.de>
# $FreeBSD$

PORTNAME=	centerim
PORTVERSION=	4.22.10
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/releases/ \
		ftp://ftp.centerim.org/releases/

MAINTAINER=	frank@altpeter.de
COMMENT=	Text mode menu- and window-driven IM interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libgpg-error.so:security/libgpg-error

USES=		iconv gmake ncurses pkgconfig python shebangfix ssl
USE_CXXSTD=	gnu++98
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-ssl --with-openssl --disable-yahoo --disable-msn
CONFLICTS=	centericq-[0-9]* centerim-devel-[0-9]*

SHEBANG_FILES=	misc/CenterIMLog2HTML.py misc/cimformathistory misc/cimextracthistory.pl
SHEBANG_LANG=	gawk
gawk_OLD_CMD=	/bin/gawk
gawk_CMD=	/usr/bin/awk

OPTIONS_DEFINE=	NLS MULTIBYTE FRIBIDI IRC JABBER GPGME RSS LJ GG DOCS

FRIBIDI_DESC=	Fribidi Support
IRC_DESC=	IRC Protocol
GPGME_DESC=	PGP encrypted Jabber messages
RSS_DESC=	RSS Support
LJ_DESC=	LiveJournal Support
GG_DESC=	Gadu-Gadu Protocol Support

OPTIONS_DEFAULT=	MULTIBYTE FRIBIDI IRC JABBER GPGME RSS LJ GG

OPTIONS_SUB=	yes

PORTDOCS=	FAQ README

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
MULTIBYTE_CONFIGURE_ENABLE=locales-fix
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_WITH=	fribidi
IRC_CONFIGURE_ENABLE=	irc
JABBER_CONFIGURE_ENABLE=jabber
RSS_CONFIGURE_ENABLE=	rss
LJ_CONFIGURE_ENABLE=	lj
GG_LIB_DEPENDS=		libgadu.so:polish/libgadu
GG_CONFIGURE_ENABLE=	gg
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_OFF=	--with-gpgme-prefix=/nonexistent

post-patch:
	@${REINPLACE_CMD} -e 's|-R$$found_dir|-Wl,-rpath,$$found_dir|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
